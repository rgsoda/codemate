#ifndef BUFFERCOMPLETIONENGINE_H
#define BUFFERCOMPLETIONENGINE_H

#include "qce/qcodecompletionengine.h"
#include <QComboBox>
#include <QListView>
#include <QTreeWidget>

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
    QTreeWidget *tree;


    QDocumentCursor actualDocumentCursor;

    bool inCompletion;
    QString toComplete;

public slots:
    void insertWord(QString word);
    void doneCompletion();
    void treeActivated(QTreeWidgetItem* item ,int col );

protected:
    bool eventFilter(QObject *obj, QEvent *ev);
private:

    void setActualCursor(QDocumentCursor &dc);
    QDocumentCursor getActualCursor();
    QPointer<QEditor> pEdit;

    int m_max;
    QString m_trig;
    QDocumentCursor m_cur;
    QAction *pForcedTrigger;

    QStringList m_triggers;



};

#endif // BUFFERCOMPLETIONENGINE_H
