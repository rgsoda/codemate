#include <QtGui>
#include <Qsci/qsciscintilla.h>
#include <Qsci/qscilexerpython.h>
#include "mainwindow.h"

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
    tabWidget = new QTabWidget(this);

    QDockWidget *dock = new QDockWidget(tr("Files"), this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea);

    model = new QFileSystemModel;
    model->setRootPath(QDir::currentPath());

    tree = new QTreeView(dock);
    tree->setModel(model);

    tree->setAnimated(false);
    tree->setIndentation(20);
    tree->setSortingEnabled(true);
    tree->setExpandsOnDoubleClick(true);
    tree->setColumnHidden(1,true);
    tree->setColumnHidden(2,true);
    tree->setColumnHidden(3,true);
    dock->setWidget(tree);
    connect(tree, SIGNAL(doubleClicked(QModelIndex)), this,
                       SLOT(doubleClicked(QModelIndex)));
    addDockWidget(Qt::LeftDockWidgetArea, dock);

    tabWidget->show();
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
    //newEditor("unnamed.txt");
}

void MainWindow::openFile(const QString &path)
{
    QString fileName = path;
    if (fileName.isNull())
        fileName = QFileDialog::getOpenFileName(this,
            tr("Open File"), "", "C++ Files (*.cpp *.h *.*)");

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QFile::ReadOnly | QFile::Text))
            newEditor(file);
    }
}

void MainWindow::closeFile(){
    delete(tabWidget->currentWidget());
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

    editor->setMarginsBackgroundColor(QColor("#333333"));
    editor->setMarginsForegroundColor(QColor("#CCCCCC"));

    editor->setFoldMarginColors(QColor("#99CC66"),QColor("#333300"));
    editor->setText(file.readAll());

    tabWidget->insertTab(0,dynamic_cast<QWidget*>(editor),file.fileName());
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

    fileMenu->addAction(tr("&Close..."), this, SLOT(closeFile()),
                        QKeySequence::Close);

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
