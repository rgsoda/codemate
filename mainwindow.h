
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QModelIndex>
#include "highlighter.h"
#include "codeeditor.h"

class QTextEdit;
class QListWidget;
class QTreeView;
class QTabWidget;
class QFileSystemModel;
class QPlainTextEdit;
class QTabBar;
class QFile;
class QsciScintilla;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

public slots:
    void about();
    void newFile();
    void openFile(const QString &path = QString());
    void closeFile();
    void doubleClicked(QModelIndex);

private:

    void setupFileMenu();
    void setupHelpMenu();
    void setupWidgets();

    QsciScintilla *newEditor(QFile &file);
    QListWidget *customerList;
    Highlighter *highlighter;
    QTreeView *tree;
    QFileSystemModel *model;
    QTabWidget *tabWidget;

};


#endif
