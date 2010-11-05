#include "buffercompletionengine.h"
#include <QStringListModel>
#include <QListView>
#include "qce/document/qdocument.h"

BufferCompletionEngine::BufferCompletionEngine(QObject *p) : QCodeCompletionEngine(p)
{
    //wordList << "adas" << "soda" << "dupa";
    completionInProgress = false;
}

BufferCompletionEngine::~BufferCompletionEngine() {
}

QCodeCompletionEngine* BufferCompletionEngine::clone() {
    return new BufferCompletionEngine(this);
}

QString BufferCompletionEngine::language() const {
    return "All";
}

QStringList BufferCompletionEngine::extensions() const {
    return QStringList() << "all";
}

void BufferCompletionEngine::run() {
}

bool BufferCompletionEngine::eventFilter(QObject *o, QEvent *e) {
    return true;
}

void BufferCompletionEngine::complete(const QDocumentCursor &c, const QString &trigger) {
    qDebug("BufferCompletionEngine::complete(const QDocumentCursor &c, const QString &trigger)");
}

void BufferCompletionEngine::complete(QCodeStream *s, const QString &trigger) {
}

void BufferCompletionEngine::completeText(const QDocumentCursor &c) {
    QDocumentCursor cc = c;
    QDocument *doc = cc.document();

    cc.movePosition(1, QDocumentCursor::PreviousWord, QDocumentCursor::KeepAnchor);
    qDebug("%s", qPrintable(cc.selectedText()));
    QWidget *editor = dynamic_cast<QWidget*>(doc->parent());
    QPoint editorPos = editor->pos();
    QPoint docPos = cc.documentPosition();
    comletionList = new QListView(editor);
    //box->pos().x = editorPos.x() + docPos.x();
    //box->pos().y = editorPos.y() + docPos.y()
//    qDebug("%d",p.x());
//    qDebug("%d",p.y());
    comletionList->move(editorPos+docPos+QPoint(120,0));
    comletionList->setModel(new QStringListModel(wordList,this));
    comletionList->setFocusPolicy(Qt::NoFocus);
    comletionList->show();
    comletionList->setFocus();
    completionInProgress=true;

}

void BufferCompletionEngine::setWords(QStringList _wordList) {
    this->wordList = _wordList;
}
