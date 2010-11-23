/********************************************************************************
** Form generated from reading UI file 'searchreplace.ui'
**
** Created: Wed Nov 17 22:36:48 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHREPLACE_H
#define UI_SEARCHREPLACE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchReplace
{
public:
    QVBoxLayout *vboxLayout;
    QFrame *frameSearch;
    QHBoxLayout *hboxLayout;
    QToolButton *bClose;
    QToolButton *bRefresh;
    QLabel *label;
    QLineEdit *leFind;
    QToolButton *bNext;
    QToolButton *bPrevious;
    QSpacerItem *spacerItem;
    QCheckBox *cbWords;
    QCheckBox *cbCursor;
    QCheckBox *cbSelection;
    QCheckBox *cbHighlight;
    QCheckBox *cbRegExp;
    QCheckBox *cbCase;
    QFrame *frameReplace;
    QHBoxLayout *hboxLayout1;
    QCheckBox *cbReplace;
    QLineEdit *leReplace;
    QSpacerItem *spacerItem1;
    QCheckBox *cbPrompt;
    QCheckBox *cbReplaceAll;
    QCheckBox *cbEscapeSeq;

    void setupUi(QWidget *SearchReplace)
    {
        if (SearchReplace->objectName().isEmpty())
            SearchReplace->setObjectName(QString::fromUtf8("SearchReplace"));
        SearchReplace->resize(801, 82);
        vboxLayout = new QVBoxLayout(SearchReplace);
        vboxLayout->setSpacing(0);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        vboxLayout->setContentsMargins(2, 2, 2, 1);
        frameSearch = new QFrame(SearchReplace);
        frameSearch->setObjectName(QString::fromUtf8("frameSearch"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frameSearch->sizePolicy().hasHeightForWidth());
        frameSearch->setSizePolicy(sizePolicy);
        frameSearch->setMinimumSize(QSize(16, 24));
        frameSearch->setMaximumSize(QSize(16777215, 16777215));
        frameSearch->setFrameShape(QFrame::NoFrame);
        frameSearch->setFrameShadow(QFrame::Plain);
        hboxLayout = new QHBoxLayout(frameSearch);
        hboxLayout->setSpacing(2);
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        bClose = new QToolButton(frameSearch);
        bClose->setObjectName(QString::fromUtf8("bClose"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(bClose->sizePolicy().hasHeightForWidth());
        bClose->setSizePolicy(sizePolicy1);
        bClose->setMinimumSize(QSize(20, 20));
        bClose->setMaximumSize(QSize(20, 20));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/closeall.png"), QSize(), QIcon::Normal, QIcon::Off);
        bClose->setIcon(icon);

        hboxLayout->addWidget(bClose);

        bRefresh = new QToolButton(frameSearch);
        bRefresh->setObjectName(QString::fromUtf8("bRefresh"));
        sizePolicy1.setHeightForWidth(bRefresh->sizePolicy().hasHeightForWidth());
        bRefresh->setSizePolicy(sizePolicy1);
        bRefresh->setMinimumSize(QSize(20, 20));
        bRefresh->setMaximumSize(QSize(20, 20));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/reload.png"), QSize(), QIcon::Normal, QIcon::Off);
        bRefresh->setIcon(icon1);

        hboxLayout->addWidget(bRefresh);

        label = new QLabel(frameSearch);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        hboxLayout->addWidget(label);

        leFind = new QLineEdit(frameSearch);
        leFind->setObjectName(QString::fromUtf8("leFind"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(leFind->sizePolicy().hasHeightForWidth());
        leFind->setSizePolicy(sizePolicy3);
        leFind->setMinimumSize(QSize(120, 22));
        leFind->setMaximumSize(QSize(120, 16777215));

        hboxLayout->addWidget(leFind);

        bNext = new QToolButton(frameSearch);
        bNext->setObjectName(QString::fromUtf8("bNext"));
        sizePolicy1.setHeightForWidth(bNext->sizePolicy().hasHeightForWidth());
        bNext->setSizePolicy(sizePolicy1);
        bNext->setMinimumSize(QSize(20, 20));
        bNext->setMaximumSize(QSize(20, 20));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/down.png"), QSize(), QIcon::Normal, QIcon::Off);
        bNext->setIcon(icon2);

        hboxLayout->addWidget(bNext);

        bPrevious = new QToolButton(frameSearch);
        bPrevious->setObjectName(QString::fromUtf8("bPrevious"));
        sizePolicy1.setHeightForWidth(bPrevious->sizePolicy().hasHeightForWidth());
        bPrevious->setSizePolicy(sizePolicy1);
        bPrevious->setMinimumSize(QSize(20, 20));
        bPrevious->setMaximumSize(QSize(20, 20));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/up.png"), QSize(), QIcon::Normal, QIcon::Off);
        bPrevious->setIcon(icon3);

        hboxLayout->addWidget(bPrevious);

        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        cbWords = new QCheckBox(frameSearch);
        cbWords->setObjectName(QString::fromUtf8("cbWords"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(cbWords->sizePolicy().hasHeightForWidth());
        cbWords->setSizePolicy(sizePolicy4);

        hboxLayout->addWidget(cbWords);

        cbCursor = new QCheckBox(frameSearch);
        cbCursor->setObjectName(QString::fromUtf8("cbCursor"));
        sizePolicy4.setHeightForWidth(cbCursor->sizePolicy().hasHeightForWidth());
        cbCursor->setSizePolicy(sizePolicy4);
        cbCursor->setChecked(true);

        hboxLayout->addWidget(cbCursor);

        cbSelection = new QCheckBox(frameSearch);
        cbSelection->setObjectName(QString::fromUtf8("cbSelection"));
        sizePolicy4.setHeightForWidth(cbSelection->sizePolicy().hasHeightForWidth());
        cbSelection->setSizePolicy(sizePolicy4);

        hboxLayout->addWidget(cbSelection);

        cbHighlight = new QCheckBox(frameSearch);
        cbHighlight->setObjectName(QString::fromUtf8("cbHighlight"));
        sizePolicy2.setHeightForWidth(cbHighlight->sizePolicy().hasHeightForWidth());
        cbHighlight->setSizePolicy(sizePolicy2);

        hboxLayout->addWidget(cbHighlight);

        cbRegExp = new QCheckBox(frameSearch);
        cbRegExp->setObjectName(QString::fromUtf8("cbRegExp"));
        sizePolicy4.setHeightForWidth(cbRegExp->sizePolicy().hasHeightForWidth());
        cbRegExp->setSizePolicy(sizePolicy4);

        hboxLayout->addWidget(cbRegExp);

        cbCase = new QCheckBox(frameSearch);
        cbCase->setObjectName(QString::fromUtf8("cbCase"));
        sizePolicy4.setHeightForWidth(cbCase->sizePolicy().hasHeightForWidth());
        cbCase->setSizePolicy(sizePolicy4);
        cbCase->setChecked(true);

        hboxLayout->addWidget(cbCase);


        vboxLayout->addWidget(frameSearch);

        frameReplace = new QFrame(SearchReplace);
        frameReplace->setObjectName(QString::fromUtf8("frameReplace"));
        QSizePolicy sizePolicy5(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(frameReplace->sizePolicy().hasHeightForWidth());
        frameReplace->setSizePolicy(sizePolicy5);
        frameReplace->setMinimumSize(QSize(16, 24));
        frameReplace->setMaximumSize(QSize(16777215, 16777215));
        frameReplace->setFrameShape(QFrame::NoFrame);
        frameReplace->setFrameShadow(QFrame::Plain);
        hboxLayout1 = new QHBoxLayout(frameReplace);
        hboxLayout1->setSpacing(2);
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        cbReplace = new QCheckBox(frameReplace);
        cbReplace->setObjectName(QString::fromUtf8("cbReplace"));
        sizePolicy4.setHeightForWidth(cbReplace->sizePolicy().hasHeightForWidth());
        cbReplace->setSizePolicy(sizePolicy4);
        cbReplace->setChecked(true);

        hboxLayout1->addWidget(cbReplace);

        leReplace = new QLineEdit(frameReplace);
        leReplace->setObjectName(QString::fromUtf8("leReplace"));
        leReplace->setEnabled(true);
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(leReplace->sizePolicy().hasHeightForWidth());
        leReplace->setSizePolicy(sizePolicy6);
        leReplace->setMinimumSize(QSize(168, 22));
        leReplace->setMaximumSize(QSize(1200, 16777215));

        hboxLayout1->addWidget(leReplace);

        spacerItem1 = new QSpacerItem(139, 24, QSizePolicy::Preferred, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem1);

        cbPrompt = new QCheckBox(frameReplace);
        cbPrompt->setObjectName(QString::fromUtf8("cbPrompt"));
        sizePolicy4.setHeightForWidth(cbPrompt->sizePolicy().hasHeightForWidth());
        cbPrompt->setSizePolicy(sizePolicy4);
        cbPrompt->setChecked(true);

        hboxLayout1->addWidget(cbPrompt);

        cbReplaceAll = new QCheckBox(frameReplace);
        cbReplaceAll->setObjectName(QString::fromUtf8("cbReplaceAll"));
        sizePolicy4.setHeightForWidth(cbReplaceAll->sizePolicy().hasHeightForWidth());
        cbReplaceAll->setSizePolicy(sizePolicy4);

        hboxLayout1->addWidget(cbReplaceAll);

        cbEscapeSeq = new QCheckBox(frameReplace);
        cbEscapeSeq->setObjectName(QString::fromUtf8("cbEscapeSeq"));
        sizePolicy4.setHeightForWidth(cbEscapeSeq->sizePolicy().hasHeightForWidth());
        cbEscapeSeq->setSizePolicy(sizePolicy4);

        hboxLayout1->addWidget(cbEscapeSeq);


        vboxLayout->addWidget(frameReplace);


        retranslateUi(SearchReplace);
        QObject::connect(cbReplace, SIGNAL(toggled(bool)), frameReplace, SLOT(setVisible(bool)));
        QObject::connect(bClose, SIGNAL(clicked()), SearchReplace, SLOT(hide()));

        QMetaObject::connectSlotsByName(SearchReplace);
    } // setupUi

    void retranslateUi(QWidget *SearchReplace)
    {
        SearchReplace->setWindowTitle(QApplication::translate("SearchReplace", "Form", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        bClose->setToolTip(QApplication::translate("SearchReplace", "Close search/replace panel", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        bClose->setText(QString());
#ifndef QT_NO_TOOLTIP
        bRefresh->setToolTip(QApplication::translate("SearchReplace", "Refresh search underlying context (as an attempt to correct search behavior)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        bRefresh->setText(QString());
        label->setText(QApplication::translate("SearchReplace", " Find :", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        leFind->setToolTip(QApplication::translate("SearchReplace", "Text or pattern to search for", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        bNext->setToolTip(QApplication::translate("SearchReplace", "Find next occurence", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        bNext->setText(QString());
#ifndef QT_NO_TOOLTIP
        bPrevious->setToolTip(QApplication::translate("SearchReplace", "Find previous occurence", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        bPrevious->setText(QString());
        cbWords->setText(QApplication::translate("SearchReplace", "Words", 0, QApplication::UnicodeUTF8));
        cbCursor->setText(QApplication::translate("SearchReplace", "Cursor", 0, QApplication::UnicodeUTF8));
        cbSelection->setText(QApplication::translate("SearchReplace", "Selection", 0, QApplication::UnicodeUTF8));
        cbHighlight->setText(QApplication::translate("SearchReplace", "Highlight all", 0, QApplication::UnicodeUTF8));
        cbRegExp->setText(QApplication::translate("SearchReplace", "Regexp", 0, QApplication::UnicodeUTF8));
        cbCase->setText(QApplication::translate("SearchReplace", "Case", 0, QApplication::UnicodeUTF8));
        cbReplace->setText(QApplication::translate("SearchReplace", "Replace :", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        leReplace->setToolTip(QApplication::translate("SearchReplace", "Replacement text", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        cbPrompt->setText(QApplication::translate("SearchReplace", "Prompt on replace", 0, QApplication::UnicodeUTF8));
        cbReplaceAll->setText(QApplication::translate("SearchReplace", "Replace all", 0, QApplication::UnicodeUTF8));
        cbEscapeSeq->setText(QApplication::translate("SearchReplace", "Escape sequences", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SearchReplace: public Ui_SearchReplace {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHREPLACE_H
