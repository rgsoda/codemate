#include "buffercompletionengine.h"
#include <QStringListModel>
#include <QComboBox>

BufferCompletionEngine::BufferCompletionEngine(QObject *p) : QCodeCompletionEngine(p)
{
    wordList << "adas" << "soda" << "dupa";
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
    cc.movePosition(1, QDocumentCursor::Start, QDocumentCursor::KeepAnchor);
    qDebug("%s", qPrintable(cc.selectedText()));
    QComboBox *box = new QComboBox();
    box->setModel(new QStringListModel(wordList,this));
    box->setFocusPolicy(Qt::NoFocus);
    box->showPopup();

}
