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
        if(this->compEngine->completionInProgress) {
            if(event->key() == Qt::Key_Up) {
                qDebug("key binging for qlistview ...");
                qDebug("remaped UP");
                return false;
            }
        }
        this->compEngine->completeText(editor->cursor());
        this->compEngine->completionInProgress=true;
        qDebug("autocomptele starts");
    }

    return QEditorInputBinding::keyPressEvent(event, editor);
}
