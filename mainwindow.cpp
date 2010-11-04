#include <QtGui>
#include "mainwindow.h"
#include <iostream>
#include "mateeditor.h"
#include "qce/qeditor.h"

#include "qce/widgets/qpanel.h"
#include "qce/qeditor.h"
#include "qce/qcodeedit.h"
#include "qce/qeditsession.h"

#include "qce/document/qdocument.h"
#include "qce/document/qdocumentline.h"
#include "qce/document/qdocumentcursor.h"

#include "qce/qformatscheme.h"
#include "qce/qlanguagefactory.h"

#include "qce/qlinemarksinfocenter.h"

#include "qce/snippets/qsnippetmanager.h"
#include "qce/snippets/qsnippetbinding.h"
#include "qce/snippets/qsnippetedit.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), snapopen(0), snippetEditor(0)
{
    initSettings();
    setupFileMenu();
    setupHelpMenu();
    setupWidgets();
    setupEditor();

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
    tree->setFocusPolicy(Qt::ClickFocus);
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
    dock->setFocusPolicy(Qt::ClickFocus);
    connect(tree, SIGNAL(doubleClicked(QModelIndex)), this,
                       SLOT(doubleClicked(QModelIndex)));
    addDockWidget(Qt::LeftDockWidgetArea, dock);

    tabWidget = new QTabWidget(this);
    tabWidget->setFocusPolicy(Qt::ClickFocus);
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
                tabWidget->setCurrentIndex(openFileWidgetList.value(path));
            } else {
                openFileWidgetList.insert(path,newEditor(path));
            }


        }
    }
}
bool MainWindow::closeActualFile() {
    QString filename = openFileWidgetList.key(tabWidget->currentIndex());
    return closeFile(filename);
}
bool MainWindow::closeFile(QString &filename)
{
    QEditor *qedit = dynamic_cast<QEditor*>(tabWidget->widget(openFileWidgetList.value(filename)));
    if ( qedit->isContentModified() )
    {
            int ret = QMessageBox::warning(
                                                    this,
                                                    tr("About to quit"),
                                                    tr(
                                                            "The open document contains unsaved modifications.\n"
                                                            "Save it as %1 ?"
                                                    ).arg(qedit->fileName()),
                                                    QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel,
                                                    QMessageBox::Yes
                                            );

            if ( ret == QMessageBox::Cancel )
            {
                    return true;
            } else if ( ret == QMessageBox::Yes ) {
                    qedit->save();
            }
    }


    openFileWidgetList.remove(filename);
    delete tabWidget->currentWidget();
    return true;
}
bool MainWindow::saveActualFile(){

    QString filename = openFileWidgetList.key(tabWidget->currentIndex());
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
    QEditor *qedit = dynamic_cast<QEditor*>(tabWidget->widget(openFileWidgetList.value(filename)));
    qedit->save();
    QApplication::restoreOverrideCursor();

    statusBar->showMessage(tr("File saved"), 2000);
    return true;
}
int MainWindow::newEditor(QString path)
{

    MateEditor *mate_editor = new MateEditor(this);
    QEditor *editor_widget = mate_editor->getEditor();
    m_languages->setLanguage(editor_widget, path);

    m_languages->addCompletionEngine(buffCompletionEngine);
    editor_widget->setCompletionEngine(buffCompletionEngine);
    buffCompletionEngine->setEditor(editor_widget);
    updateCompleter();

    editor_widget->load(path);
    editor_widget->setInputBinding(m_snippetBinding);
    editor_widget->addInputBinding(completionBinding);

    editSession->addEditor(editor_widget);
    int nextIndex = tabWidget->currentIndex()+1;
    tabWidget->insertTab(nextIndex, editor_widget ,QFileInfo(path).fileName());
    tabWidget->setCurrentIndex(nextIndex);


    return nextIndex;

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
                        QKeySequence(Qt::CTRL + Qt::Key_P));

    fileMenu->addAction(tr("&Close..."), this, SLOT(closeActualFile()),
                        QKeySequence::Close);

    fileMenu->addAction(tr("&Save..."), this, SLOT(saveActualFile()),
                        QKeySequence::Save);

    fileMenu->addAction(tr("E&xit"), qApp, SLOT(quit()),
                        QKeySequence::Quit);

    fileMenu->addAction(tr("S&nippet Editor"), this, SLOT(showSnippetEditor()),
                        QKeySequence(Qt::CTRL+Qt::ALT+Qt::Key_S));

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

void MainWindow::setupEditor() {
    m_formats = new QFormatScheme("/home/soda/.codemate/qxs/formats.qxf", this);
    QDocument::setDefaultFormatScheme(m_formats);

    QLineMarksInfoCenter::instance()->loadMarkTypes("/home/soda/.codemate/qxs/marks.qxm");

    editSession = new QEditSession("session", this);

    m_snippetManager = new QSnippetManager(this);

    m_snippetManager->loadSnippetsFromDirectory("/home/soda/.codemate/snippets");
    m_snippetBinding = new QSnippetBinding(m_snippetManager);


    m_languages = new QLanguageFactory(m_formats, this);
    m_languages->addDefinitionPath("/home/soda/.codemate/qxs/");

    buffCompletionEngine = new BufferCompletionEngine();
    completionBinding = new CompleteBinding(buffCompletionEngine);

}

QLanguageFactory * MainWindow::getEditorLanguageFactory(){
    return m_languages;
}
QSnippetBinding * MainWindow::getEditorSnippetBinding() {
    return m_snippetBinding;
}

void MainWindow::showSnippetEditor() {
    if(snippetEditor == 0) {
        snippetEditor = new SnippetEditor(this, m_snippetManager);
    }
    snippetEditor->show();
}
void MainWindow::updateCompleter()
{
    QStringList words;
    words << "soda" << "loda";
    //latexCompleter->setWords(words);
}
