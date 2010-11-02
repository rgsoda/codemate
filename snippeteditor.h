#ifndef SNIPPETEDITOR_H
#define SNIPPETEDITOR_H

#include <QDialog>
#include "qce/snippets/qsnippetedit.h"
class SnippetEditor : public QDialog
{
    Q_OBJECT
public:
    explicit SnippetEditor(QWidget *parent = 0, QSnippetManager *manager = 0);

signals:

public slots:

private:
    QSnippetEdit *qSnippetEdit;

};

#endif // SNIPPETEDITOR_H
