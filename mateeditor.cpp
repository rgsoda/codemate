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


MateEditor::MateEditor(MainWindow *parent) :
    QWidget(parent)
{

    mainWindow = parent;
    m_editControl = new QCodeEdit(this);
    m_editControl->addPanel("Line Mark Panel", QCodeEdit::West, true);
    m_editControl->addPanel("Line Number Panel", QCodeEdit::West, true);
    m_editControl->addPanel("Fold Panel", QCodeEdit::West, true);
    m_editControl->addPanel("Line Change Panel", QCodeEdit::West, true);
    m_editControl->addPanel("Status Panel", QCodeEdit::South, true);
    m_editControl->addPanel("Goto Line Panel", QCodeEdit::South);
    m_editControl->addPanel("Search Replace Panel", QCodeEdit::South);
    //m_editControl->editor()->setInputBinding(m_snippetBinding);
}

QEditor *MateEditor::getEditor() {
    return m_editControl->editor();

}
