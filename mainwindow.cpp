#include <QtGui>
#include <Qsci/qsciscintilla.h>
#include <Qsci/qscilexerpython.h>
#include "mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
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
    font.setPointSize(9);

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

    QFile styleDefinition(QDir::homePath()+"/.codemate/codemate.style");
    if (!styleDefinition.open(QIODevice::ReadOnly | QIODevice::Text))
        statusBar->showMessage("CSSStyle not found");
    QString content = styleDefinition.readAll();

    tabWidget->setStyleSheet(content);
    tabWidget->show();

    connect(tabWidget,SIGNAL(tabCloseRequested(int)),this,SLOT(tabCloseRequested(int)));
    setCentralWidget(tabWidget);

    statusBar = new QStatusBar(this);
    statusBar->setFont(font);
    setStatusBar(statusBar);

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
    QFile file("unnamed.txt");
    newEditor(file);
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
                openFileWidgetList.insert(path,newEditor(file));
                tabWidget->setCurrentIndex(0);
            }
        }
    }
}
bool MainWindow::closeActualFile() {
    QString filename = openFileWidgetList.key(tabWidget->currentWidget());
    QsciScintilla *editor = dynamic_cast<QsciScintilla*>(tabWidget->currentWidget());
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
    QsciScintilla *editor = dynamic_cast<QsciScintilla*>(openFileWidgetList.value(filename));
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

    out << dynamic_cast<QsciScintilla*>(tabWidget->currentWidget())->text();
    QApplication::restoreOverrideCursor();

    statusBar->showMessage(tr("File saved"), 2000);
    dynamic_cast<QsciScintilla*>(tabWidget->currentWidget())->setModified(false);
    return true;
}
QsciScintilla *MainWindow::newEditor(QFile &file)
{
    QFont font;
    QString fontName = settings.value("editor/font-name","Courier").toString();
    std::cout << fontName.toStdString() << std::endl;
    font.setFamily(settings.value("editor/font-name","Monaco").toString());
    font.setFixedPitch(settings.value("editor/font-fixed-pitch",true).toBool());
    font.setPointSize(settings.value("editor/font-size",9).toInt());

    QsciScintilla *editor = new QsciScintilla(this);
    editor->setAutoIndent(true);
    editor->setAutoCompletionThreshold(2);
    editor->setAutoCompletionSource(QsciScintilla::AcsAPIs);

    QsciLexerPython *lexer = new QsciLexerPython();

    lexer->setDefaultFont(font);
    lexer->setFont(font);

    editor->setLexer(lexer);
    editor->setMarginsFont(font);

    editor->setMarginWidth(0, 20);
    editor->setMarginLineNumbers(0, true);

    editor->setEdgeMode(QsciScintilla::EdgeLine);
    editor->setEdgeColumn(settings.value("editor/margin-edge-column",80).toInt());
    editor->setEdgeColor(QColor(settings.value("editor/margin-edge-color","#FF0000").toString()));

    editor->setFolding(QsciScintilla::PlainFoldStyle);
    editor->setBraceMatching(QsciScintilla::SloppyBraceMatch);

    editor->setAutoCompletionSource(QsciScintilla::AcsAll);

    editor->setCaretLineVisible(settings.value("editor/carret-line-visible",true).toBool());
    editor->setCaretLineBackgroundColor(
            QColor(settings.value("editor/carret-line-color","#E3E3E3").toString()));

    editor->setMarginsBackgroundColor(
            QColor(settings.value("editor/margin-background-color","#E3E3E3").toString()));
    editor->setMarginsForegroundColor(
            QColor(settings.value("editor/margin-foregroud-color","#A7A7AF").toString()));

    editor->setFoldMarginColors(
            QColor(settings.value("editor/fold-margin-background-color","#E3E3E3").toString()),
            QColor(settings.value("editor/margin-foregroud-color","#E3E3E3").toString()));
    editor->setText(file.readAll());
    editor->setModified(false);

    QFileInfo *fileInfo = new QFileInfo(file);
    tabWidget->insertTab(tabWidget->currentIndex(), editor,fileInfo->completeBaseName());
    return editor;

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
    snapopen = new SnapOpen(this);
    snapopen->show();
}
void MainWindow::tabCloseRequested(int index) {
    delete tabWidget->widget(index);
}
