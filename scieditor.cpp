#include <QtGui>
#include "scieditor.h"
#include <Qsci/qsciscintilla.h>
#include <Qsci/qscilexerpython.h>
#include <iostream>

SciEditor::SciEditor(QWidget *parent)
{
    initSettings();
    setupEditor();
}

void SciEditor::initSettings() {
    QString path = QDir::homePath() + "/.codemate/codemate.ini";
    QSettings settings(path,QSettings::IniFormat);
}

void SciEditor::setupEditor() {
    QFont font;
    const QStringList childKeys = settings.childKeys();
    foreach (const QString &childKey, childKeys)
            qDebug() << settings.value(childKey);

    font.setFamily(settings.value("font-name","Monaco").toString());
    font.setFixedPitch(settings.value("font-fixed-pitch",true).toBool());
    font.setPointSize(settings.value("font-size",9).toInt());


    this->setAutoIndent(true);
    this->setAutoCompletionThreshold(2);
    this->setAutoCompletionSource(QsciScintilla::AcsAPIs);

    QsciLexerPython *lexer = new QsciLexerPython();

    lexer->setDefaultFont(font);
    lexer->setFont(font);

    this->setLexer(lexer);
    this->setMarginsFont(font);

    this->setSelectionToEol(false);

    this->setMarginWidth(0, 20);
    this->setMarginLineNumbers(0, true);

    this->setEdgeMode(QsciScintilla::EdgeLine);
    this->setEdgeColumn(settings.value("margin-edge-column",80).toInt());
    this->setEdgeColor(QColor(settings.value("margin-edge-color","#FF0000").toString()));

    this->setFolding(QsciScintilla::PlainFoldStyle);
    this->setBraceMatching(QsciScintilla::SloppyBraceMatch);

    this->setAutoCompletionSource(QsciScintilla::AcsAll);

    this->setCaretLineVisible(settings.value("carret-line-visible",true).toBool());
    this->setCaretLineBackgroundColor(
            QColor(settings.value("carret-line-color","#E3E3E3").toString()));

    this->setMarginsBackgroundColor(
            QColor(settings.value("margin-background-color","#E3E3E3").toString()));
    this->setMarginsForegroundColor(
            QColor(settings.value("margin-foregroud-color","#A7A7AF").toString()));

    this->setFoldMarginColors(
            QColor(settings.value("fold-margin-background-color","#E3E3E3").toString()),
            QColor(settings.value("margin-foregroud-color","#E3E3E3").toString()));

    connect(this,SIGNAL(SCN_CHARADDED(int)),this,SLOT(charAdded(int)));
    connect(this,SIGNAL(cursorPositionChanged(int,int)),this,SLOT(cursorPositionChanged(int,int)));

}


void SciEditor::charAdded(int ch){
    std::cout << ch << std::endl;
    int line, index = 0;

}


void SciEditor::cursorPositionChanged (int line, int pos) {
    //this->setSelection(line,pos,line+10,pos+10);
}
