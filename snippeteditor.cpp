#include "snippeteditor.h"

SnippetEditor::SnippetEditor(QWidget *parent, QSnippetManager *manager) :
    QDialog(parent)
{
    this->setModal(true);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    qSnippetEdit = new QSnippetEdit(manager,this);
    mainLayout->addWidget(qSnippetEdit);
    setLayout(mainLayout);
    setWindowTitle(tr("Snippet Editor"));
    resize(400, 400);
}
