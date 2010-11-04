#ifndef COMPLETEBINDING_H
#define COMPLETEBINDING_H
#include "qeditorinputbinding.h"
#include "buffercompletionengine.h"

class CompleteBinding : public QEditorInputBinding
{
public:
    CompleteBinding(BufferCompletionEngine *eng);
    virtual QString id() const;
    virtual QString name() const;

    virtual bool keyPressEvent(QKeyEvent *event, QEditor *editor);
private:
    BufferCompletionEngine *compEngine;
};

#endif // COMPLETEBINDING_H
