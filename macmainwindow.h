#ifndef MACMAINWINDOW_H
#define MACMAINWINDOW_H

#include <QtGui>

#ifdef Q_WS_MAC

#import <qmaccocoaviewcontainer_mac.h>

#ifdef QT_MAC_USE_COCOA
class SearchWidget : public QMacCocoaViewContainer
{
    Q_OBJECT
public:
    SearchWidget(QWidget *parent = 0);
    ~SearchWidget();

    QSize sizeHint() const;
private:
};

#else
#include <Carbon/Carbon.h>

// The SearchWidget class wraps a native HISearchField.
class SearchWidget : public QWidget
{
    Q_OBJECT
private:
    HIViewRef searchField;
    CFStringRef searchFieldText;

public:
    QSize sizeHint() const;
    SearchWidget(QWidget *parent = 0);
    ~SearchWidget();
};

#endif

QMenu *createMenu(QWidget *parent);

class SearchWrapper : public QWidget
{
Q_OBJECT
public:
    SearchWrapper(QWidget *parent = 0);
    QSize sizeHint() const;
    QWidget *s;
};

class Spacer : public QWidget
{
Q_OBJECT
public:
    Spacer(QWidget *parent = 0);
    QSize sizeHint() const;
};

class MacSplitterHandle : public QSplitterHandle
{
Q_OBJECT
public:
    MacSplitterHandle(Qt::Orientation orientation, QSplitter *parent);
    void paintEvent(QPaintEvent *);
    QSize sizeHint() const;
};

class MacSplitter : public QSplitter
{
public:
    QSplitterHandle *createHandle();
};

class MacMainWindow : public QMainWindow
{
Q_OBJECT
public:
    MacMainWindow();
    ~MacMainWindow();
    QAbstractItemModel *createItemModel();
    void resizeEvent(QResizeEvent *e);
    QAbstractItemModel *createDocumentModel();
public:
    QSplitter *splitter;
    QSplitter *horizontalSplitter;
    QTreeView *sidebar;
    QListView *documents;
    QTextEdit *textedit;
    QVBoxLayout *layout;
    SearchWidget *searchWidget;
    QToolBar * toolBar;
};

#endif // Q_WS_MAC

#endif //MACMAINWINDOW_H
