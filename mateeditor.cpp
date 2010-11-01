#include "mateeditor.h"

#include "qce/widgets/qpanel.h"
#include "qce/qeditor.h"
#include "qce/qcodeedit.h"
#include "qce/qeditsession.h"

#include "qce/document/qdocument.h"
#include "qce/document/qdocumentline.h"
#include "qce/document/qdocumentcursor.h"

#include "qce/qformatscheme.h"
#include "qce/qlanguagefactory.h"

#include "qce/qlinemarksinfocenter.h"


MateEditor::MateEditor(QWidget *parent) :
    QWidget(parent)
{

    // QCE setup
    m_formats = new QFormatScheme("qxs/python.qxf", this);
    QDocument::setDefaultFormatScheme(m_formats);

    QLineMarksInfoCenter::instance()->loadMarkTypes("qxs/marks.qxm");


    m_session = new QEditSession("session", this);

//    m_snippetManager = new QSnippetManager(this);
//    m_snippetManager->loadSnippetsFromDirectory("snippets");

//    m_snippetBinding = new QSnippetBinding(m_snippetManager);


    m_languages = new QLanguageFactory(m_formats, this);
    m_languages->addDefinitionPath("qxs");
    m_editControl = new QCodeEdit(this);
    m_editControl
            ->addPanel("Line Mark Panel", QCodeEdit::West, true)
            ;//->setShortcut(QKeySequence("F6"));

    m_editControl
            ->addPanel("Line Number Panel", QCodeEdit::West, true)
            ;//->setShortcut(QKeySequence("F11"));

    m_editControl
            ->addPanel("Fold Panel", QCodeEdit::West, true)
            ;//->setShortcut(QKeySequence("F9"));

    m_editControl
            ->addPanel("Line Change Panel", QCodeEdit::West, true)
            ; //->setShortcut(QKeySequence("F11"));

    m_editControl
            ->addPanel("Status Panel", QCodeEdit::South, true);

    m_editControl
            ->addPanel("Goto Line Panel", QCodeEdit::South);

    m_editControl
            ->addPanel("Search Replace Panel", QCodeEdit::South);

//    m_editControl->editor()->setInputBinding(m_snippetBinding);


}

QEditor *MateEditor::getEditor() {
    return m_editControl->editor();

}
