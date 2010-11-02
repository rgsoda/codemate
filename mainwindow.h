
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QModelIndex>
#include <QSettings>
#include <snapopen.h>
#include <snippeteditor.h>
#include <mateeditor.h>
#include "qce/qeditsession.h"

class QTextEdit;
class QListWidget;
class QTreeView;
class QTabWidget;
class QFileSystemModel;
class QPlainTextEdit;
class QTabBar;
class QFile;
class QEditor;
class QSettings;

class QEditSession;
class QEditor;
class QCodeEdit;
class QEditConfig;
class QFormatScheme;
class QLanguageFactory;

class QSnippetBinding;
class QSnippetManager;
class MateEditor;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    void openFile(QString &path);

public slots:
    void about();
    void newFile();

    void openFile();

    bool closeFile(QString &filename);
    bool closeActualFile();

    bool saveFile(QString &filename);
    bool saveActualFile();

    void doubleClicked(QModelIndex);
    void tabCloseRequested(int);

    void snapOpen();

    void showSnippetEditor();

    QLanguageFactory* getEditorLanguageFactory();
    QSnippetBinding* getEditorSnippetBinding();

private:

    void setupFileMenu();
    void setupHelpMenu();
    void setupWidgets();
    void setupEditor();
    void initSettings();


    //SciEditor *newEditor(QFile &file);
    int newEditor(QString path);
    QTreeView *tree;
    QFileSystemModel *model;
    QTabWidget *tabWidget;
    QStatusBar *statusBar;
    QMap<QString,int> openFileWidgetList;
    QSettings settings;
    SnapOpen *snapopen;
    SnippetEditor *snippetEditor;
    QEditSession *editSession;

    QEditConfig *m_config;

    QCodeEdit *m_editControl;
    QFormatScheme *m_formats;
    QLanguageFactory *m_languages;

    QSnippetBinding *m_snippetBinding;
    QSnippetManager *m_snippetManager;

};


#endif
