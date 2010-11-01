#ifndef MATEEDITOR_H
#define MATEEDITOR_H

#include <QWidget>
#include "qce/qeditor.h"

class QEditor;
class QCodeEdit;
class QEditConfig;
class QEditSession;
class QFormatScheme;
class QLanguageFactory;

class QSnippetBinding;
class QSnippetManager;

class MateEditor : public QWidget
{
    Q_OBJECT
public:
    explicit MateEditor(QWidget *parent = 0);
    bool isModified() { return true; }
    QEditor *getEditor();

signals:

public slots:
private:
    QEditSession *m_session;

    QEditConfig *m_config;

    QCodeEdit *m_editControl;
    QFormatScheme *m_formats;
    QLanguageFactory *m_languages;

    //QSnippetBinding *m_snippetBinding;
    //QSnippetManager *m_snippetManager;
};

#endif // MATEEDITOR_H
