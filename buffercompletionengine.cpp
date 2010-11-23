#include "buffercompletionengine.h"
#include <QStringListModel>
#include <QListView>
#include <QComboBox>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QFrame>
#include <QEvent>
#include <QKeyEvent>
#include "qce/document/qdocument.h"
#include "qce/document/qdocumentline.h"
#include "qce/qeditor.h"

BufferCompletionEngine::BufferCompletionEngine(QObject *p) : QCodeCompletionEngine(p) , tree(0)
{


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


void BufferCompletionEngine::completeText(const QDocumentCursor &c) {
    QDocumentCursor cc = c;
    setActualCursor(cc);
    QDocument *doc = cc.document();

    cc.movePosition(1, QDocumentCursor::PreviousWord, QDocumentCursor::KeepAnchor);
    qDebug("%s", qPrintable(cc.selectedText()));
    bool hasCompleteWords = false;
    if (cc.selectedText().length() > 2) {
            QWidget *editor = dynamic_cast<QWidget*>(doc->parent());

            if(tree == 0 ) {
                tree = new QTreeWidget(editor);
                tree->setFrameShape( QFrame::NoFrame );
                tree->setWindowFlags(Qt::Popup);
                tree->setColumnCount( 1 );
                tree->setRootIsDecorated( false );
                tree->headerItem()->setHidden(true);
                tree->setEditTriggers( QTreeWidget::NoEditTriggers );
                tree->setSelectionBehavior( QTreeWidget::SelectRows );
                tree->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
                tree->setMouseTracking( true );
                tree->installEventFilter( false );
                tree->setAutoScroll(true);

                connect( tree, SIGNAL(itemActivated(QTreeWidgetItem*,int)), this, SLOT(treeActivated(QTreeWidgetItem*,int)) );

            }
            tree->clear();
            // populate words
            QStringList str;
            for( int k = 0; k < wordList.count(); k++ )
            {
                str.clear();
                if (wordList[k].startsWith(cc.selectedText()) ) {

                  str << wordList[k];
                  new QTreeWidgetItem(tree,str);
                  hasCompleteWords = true;

              }
        }


        QEditor *e = dynamic_cast<QEditor*>(editor);
        QRect rect = e->lineRect(cc.lineNumber());

        tree->move(editor->mapToGlobal(QPoint(0,0)+QPoint(cc.documentPosition().x()+70,rect.y())));

        tree->adjustSize();
        if(hasCompleteWords) {
            tree->show();
            tree->setFocus();
            inCompletion = true;
            toComplete = cc.selectedText();
        }
    }


}

void BufferCompletionEngine::setWords(QStringList _wordList) {
    this->wordList = _wordList;
}


void BufferCompletionEngine::insertWord(QString word) {
    actualDocumentCursor.insertText(word.remove(toComplete),false);
    doneCompletion();
}

void BufferCompletionEngine::setActualCursor(QDocumentCursor &dc) {
    this->actualDocumentCursor = dc;
}

void BufferCompletionEngine::doneCompletion() {
    if(this->tree != 0) {
        this->tree->setVisible(false);
        editor()->setFocus();
        inCompletion = false;
        toComplete = "";
    }
}

QDocumentCursor BufferCompletionEngine::getActualCursor() {
    return this->actualDocumentCursor;
}

bool BufferCompletionEngine::eventFilter(QObject *o, QEvent *e)
{
//        qDebug("eventFilter");
//        if ( !e || !o || (e->type() != QEvent::KeyPress) || (o != pEdit) )
//                //qDebug("eventFilter return false");
//                return false;

//        qDebug("should trigger completion?");

//        QDocumentCursor cur = editor()->cursor();
//        QKeyEvent *k = static_cast<QKeyEvent*>(e);

//        QString s, txt = s = k->text();

//        int count = txt.count();

//        if ( txt.isEmpty() || m_triggers.isEmpty() )
//                return false; // QThread::eventFilter(o, e);

//        qDebug("should trigger completion? (bis)");

//        if ( count > m_max )
//        {
//                txt = txt.right(m_max);

//        } else if ( count < m_max ) {

//                QDocumentCursor c(cur);
//                c.movePosition(m_max - count, QDocumentCursor::Left, QDocumentCursor::KeepAnchor);

//                qDebug("prev text : %s", qPrintable(c.selectedText()));

//                txt.prepend(c.selectedText());
//        }

//        qDebug("text : %s", qPrintable(txt));

//        foreach ( QString trig, m_triggers )
//        {
//                if ( txt.endsWith(trig) )
//                {
//                        editor()->write(s);

//                        cur = editor()->cursor();
//                        cur.movePosition(trig.count(), QDocumentCursor::PreviousCharacter);

//                        // notify completion trigger
//                        emit completionTriggered(trig);

//                        //get rid of previous calltips/completions
//                        editor()->setFocus();

//                        // trigger completion
//                        complete(cur, trig);

//                        return true;
//                }
//        }

//        return false;
}

void BufferCompletionEngine::treeActivated(QTreeWidgetItem *item, int col) {
    insertWord(item->text(col));
}

