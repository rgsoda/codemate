#ifndef MATEEDITOR_H
#define MATEEDITOR_H

#include <QWidget>
#include "qce/qeditor.h"
#include "mainwindow.h"

class QEditor;
class QCodeEdit;
class MainWindow;

class MateEditor : public QWidget
{
    Q_OBJECT
public:
    explicit MateEditor(MainWindow *parent = 0);
    bool isModified() { return true; }
    QEditor *getEditor();
    void load(const QString &file);
signals:

public slots:
private:
    QCodeEdit *m_editControl;
    MainWindow *mainWindow;
};

#endif // MATEEDITOR_H
