#include <QtGui>
#include <Qsci/qsciscintilla.h>
#include <Qsci/qscilexerpython.h>
#include "mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupFileMenu();
    setupHelpMenu();

    setupWidgets();

    setWindowTitle(tr("CodeMate"));
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
    font.setFamily("Monaco");
    font.setFixedPitch(true);
    font.setPointSize(9);

    QsciScintilla *editor = new QsciScintilla(this);
    QsciLexerPython *lexer = new QsciLexerPython();

    lexer->setDefaultFont(font);
    lexer->setFont(font);

    editor->setLexer(lexer);
    editor->setMarginsFont(font);

    editor->setMarginWidth(0, 20);
    editor->setMarginLineNumbers(0, true);

    editor->setEdgeMode(QsciScintilla::EdgeLine);
    editor->setEdgeColumn(80);
    editor->setEdgeColor(QColor("#FF0000"));

    editor->setFolding(QsciScintilla::PlainFoldStyle);
    editor->setBraceMatching(QsciScintilla::SloppyBraceMatch);

    editor->setAutoCompletionSource(QsciScintilla::AcsAll);

    editor->setCaretLineVisible(true);
    editor->setCaretLineBackgroundColor(QColor("#CDA869"));

    editor->setMarginsBackgroundColor(QColor("#E3E3E3"));
    editor->setMarginsForegroundColor(QColor("#A7A7AF"));

    editor->setFoldMarginColors(QColor("#E3E3E3"),QColor("#E3E3E3"));
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

void MainWindow::tabCloseRequested(int index) {
    delete tabWidget->widget(index);
}

