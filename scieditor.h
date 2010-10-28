#ifndef SCIEDITOR_H
#define SCIEDITOR_H

#include <QSettings>
#include "Qsci/qsciscintilla.h"

class QsciScintilla;

class SciEditor : public QsciScintilla
{
    Q_OBJECT

public:
    SciEditor(QWidget *parent);

private slots:
    void charAdded(int ch);
    void cursorPositionChanged (int line, int pos);

private:
    void initSettings();
    void setupEditor();
    QSettings settings;
};

#endif // SCIEDITOR_H
