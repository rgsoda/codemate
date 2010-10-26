
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QModelIndex>


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

    void openFile();
    void openFile(QString &path);

    bool closeFile(QString &filename);
    bool closeActualFile();

    bool saveFile(QString &filename);
    bool saveActualFile();

    void doubleClicked(QModelIndex);
    void tabCloseRequested(int);

private:

    void setupFileMenu();
    void setupHelpMenu();
    void setupWidgets();

    QsciScintilla *newEditor(QFile &file);

    QTreeView *tree;
    QFileSystemModel *model;
    QTabWidget *tabWidget;
    QStatusBar *statusBar;

    QMap<QString,QWidget *> openFileWidgetList;

};


#endif
