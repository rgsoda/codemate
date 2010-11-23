#include "completebinding.h"
#include <QKeyEvent>
#include "qce/qeditor.h"
CompleteBinding::CompleteBinding(BufferCompletionEngine *eng)
{
    this->compEngine = eng;
}

QString CompleteBinding::id() const
{
        return "complete binding";
}

QString CompleteBinding::name() const
{
        return "complete binding";
}

bool CompleteBinding::keyPressEvent(QKeyEvent *event, QEditor *editor)
{

    if ( (event->modifiers() & Qt::CTRL) && (event->key() == Qt::Key_Space || event->text() == " ") ) {
        this->compEngine->completeText(editor->cursor());
    }
    return QEditorInputBinding::keyPressEvent(event, editor);
}
