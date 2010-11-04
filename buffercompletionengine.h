#ifndef BUFFERCOMPLETIONENGINE_H
#define BUFFERCOMPLETIONENGINE_H

#include "qce/qcodecompletionengine.h"
#include "QCompleter"

class QComleter;
class BufferCompletionEngine : public QCodeCompletionEngine
{
    Q_OBJECT
public:
    BufferCompletionEngine(QObject *p = 0);
    virtual ~BufferCompletionEngine();
    virtual QCodeCompletionEngine* clone();

    virtual QString language() const;
    virtual QStringList extensions() const;

    void setWords(QStringList wordList);
    QStringList wordList;

    void completeText(const QDocumentCursor& c);
protected:
    virtual void run();
    virtual bool eventFilter(QObject *o, QEvent *e);

    virtual void complete(QCodeStream *s, const QString& trigger);
    virtual void complete(const QDocumentCursor& c, const QString& trigger);


};

#endif // BUFFERCOMPLETIONENGINE_H
