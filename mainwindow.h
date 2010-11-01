
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QModelIndex>
#include <QSettings>
#include <snapopen.h>
#include <mateeditor.h>

class QTextEdit;
class QListWidget;
class QTreeView;
class QTabWidget;
class QFileSystemModel;
class QPlainTextEdit;
class QTabBar;
class QFile;

class QSettings;

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


private:

    void setupFileMenu();
    void setupHelpMenu();
    void setupWidgets();
    void initSettings();

    //SciEditor *newEditor(QFile &file);
    MateEditor *newEditor(QString path);
    QTreeView *tree;
    QFileSystemModel *model;
    QTabWidget *tabWidget;
    QStatusBar *statusBar;
    QMap<QString,QWidget *> openFileWidgetList;
    QSettings settings;
    SnapOpen *snapopen;
};


#endif
