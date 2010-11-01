#include <QtGui>
#include "mainwindow.h"
#include <iostream>
#include "mateeditor.h"
#include "qce/qeditor.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), snapopen(0)
{
    initSettings();
    setupFileMenu();
    setupHelpMenu();
    setupWidgets();

    setWindowTitle(tr("CodeMate"));
    resize(800, 600);

}

void MainWindow::initSettings() {
    QString path = QDir::homePath() + "/.codemate/codemate.ini";
    QSettings settings(path,QSettings::IniFormat);
}
void MainWindow::setupWidgets()
{

    QFont font;
    font.setFamily("Monaco");
    font.setFixedPitch(true);
    font.setPointSize(10);

    QDockWidget *dock = new QDockWidget(tr("Files"), this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea);

    model = new QFileSystemModel;
    model->setRootPath(QDir::currentPath());
    tree = new QTreeView(dock);
    tree->setModel(model);
    tree->setRootIndex(model->index(QDir::currentPath()));
    tree->setFont(font);
    tree->setAnimated(false);
    tree->setIndentation(20);
    tree->setSortingEnabled(true);
    tree->setExpandsOnDoubleClick(true);
    tree->setColumnHidden(1,true);
    tree->setColumnHidden(2,true);
    tree->setColumnHidden(3,true);
    tree->sortByColumn(0);
    dock->setWidget(tree);
    connect(tree, SIGNAL(doubleClicked(QModelIndex)), this,
                       SLOT(doubleClicked(QModelIndex)));
    addDockWidget(Qt::LeftDockWidgetArea, dock);

    tabWidget = new QTabWidget(this);
    tabWidget->setTabShape(QTabWidget::Rounded);
    tabWidget->setTabsClosable(true);
    tabWidget->setFont(font);

    statusBar = new QStatusBar(this);
    statusBar->setFont(font);
    setStatusBar(statusBar);

    QFile styleDefinition(QDir::homePath()+"/.codemate/a.qss");
    if (!styleDefinition.open(QIODevice::ReadOnly | QIODevice::Text))
        statusBar->showMessage("CSSStyle not found");
    QString content = styleDefinition.readAll();

    tabWidget->setStyleSheet(content);
    tabWidget->show();

    connect(tabWidget,SIGNAL(tabCloseRequested(int)),this,SLOT(tabCloseRequested(int)));
    setCentralWidget(tabWidget);

}
void MainWindow::about()
{
    QMessageBox::about(this, tr("About Syntax Highlighter"),
                tr("<p>The <b>Syntax Highlighter</b> example shows how " \
                   "to perform simple syntax highlighting by subclassing " \
                   "the QSyntaxHighlighter class and describing " \
                   "highlighting rules using regular expressions.</p>"));
}
void MainWindow::newFile()
{

    newEditor("unnamed.txt");
}
void MainWindow::openFile() {
    QString path = QFileDialog::getOpenFileName(this,
        tr("Open File"), "", "All Files (*.*)");
    openFile(path);
}
void MainWindow::openFile(QString &path)
{
    if (!path.isEmpty()) {
        QFile file(path);
        if (file.open(QFile::ReadOnly | QFile::Text)) {
            if (openFileWidgetList.contains(path)) {
                tabWidget->setCurrentWidget(openFileWidgetList.value(path));
            } else {
                openFileWidgetList.insert(path,newEditor(path));
                tabWidget->setCurrentIndex(0);
            }
        }
    }
}
bool MainWindow::closeActualFile() {
    QString filename = openFileWidgetList.key(tabWidget->currentWidget());
    MateEditor *editor = dynamic_cast<MateEditor*>(tabWidget->currentWidget());
    if(editor->isModified()){
        statusBar->showMessage(tr("Save first"), 2000);
        return false;
    }
    openFileWidgetList.remove(filename);
    delete tabWidget->currentWidget();
    return true;
}
bool MainWindow::closeFile(QString &filename)
{
    MateEditor *editor = dynamic_cast<MateEditor*>(openFileWidgetList.value(filename));
    if(editor->isModified()){
        statusBar->showMessage(tr("Save first"), 2000);
        return false;
    }
    openFileWidgetList.remove(filename);
    delete tabWidget->currentWidget();
    return true;
}
bool MainWindow::saveActualFile(){
    QString filename = openFileWidgetList.key(tabWidget->currentWidget());
    return saveFile(filename);
}
bool MainWindow::saveFile(QString &filename) {
    QFile file(filename);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Application"),
                             tr("Cannot write file %1:\n%2.")
                             .arg(filename)
                             .arg(file.errorString()));
        return false;
    }

    QTextStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);

    //out << dynamic_cast<CodeEditor*>(tabWidget->currentWidget())->document()->toPlainText();
    QApplication::restoreOverrideCursor();

    statusBar->showMessage(tr("File saved"), 2000);
    //dynamic_cast<CodeEditor*>(tabWidget->currentWidget())->setModified(false);
    return true;
}
MateEditor *MainWindow::newEditor(QString path)
{

    MateEditor *mate_editor = new MateEditor(this);
    QEditor *editor_widget = mate_editor->getEditor();
    editor_widget->load(path);
    editor_widget->setFileName(path);
    tabWidget->insertTab(tabWidget->currentIndex(), editor_widget ,path);
    tabWidget->setMovable(true);
    return mate_editor;

}
void MainWindow::setupFileMenu()
{
    QMenu *fileMenu = new QMenu(tr("&File"), this);
    menuBar()->addMenu(fileMenu);

    fileMenu->addAction(tr("&New"), this, SLOT(newFile()),
                        QKeySequence::New);

    fileMenu->addAction(tr("&Open..."), this, SLOT(openFile()),
                        QKeySequence::Open);

    fileMenu->addAction(tr("&SnapOpen..."), this, SLOT(snapOpen()),
                        QKeySequence::Print);

    fileMenu->addAction(tr("&Close..."), this, SLOT(closeActualFile()),
                        QKeySequence::Close);

    fileMenu->addAction(tr("&Save..."), this, SLOT(saveActualFile()),
                        QKeySequence::Save);

    fileMenu->addAction(tr("E&xit"), qApp, SLOT(quit()),
                        QKeySequence::Quit);
}
void MainWindow::setupHelpMenu()
{
    QMenu *helpMenu = new QMenu(tr("&Help"), this);
    menuBar()->addMenu(helpMenu);

    helpMenu->addAction(tr("&About"), this, SLOT(about()));
    helpMenu->addAction(tr("About &Qt"), qApp, SLOT(aboutQt()));
}
void MainWindow::doubleClicked(QModelIndex index) {
    QString fpath = model->filePath(index);
    this->openFile(fpath);
}
void MainWindow::snapOpen() {
    if(snapopen == 0) {
        snapopen = new SnapOpen(this);
    }
    snapopen->clearFilter();
    snapopen->show();
}
void MainWindow::tabCloseRequested(int index) {
    delete tabWidget->widget(index);
}


