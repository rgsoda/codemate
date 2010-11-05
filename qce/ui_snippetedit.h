/********************************************************************************
** Form generated from reading UI file 'snippetedit.ui'
**
** Created: Mon Nov 1 18:36:11 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SNIPPETEDIT_H
#define UI_SNIPPETEDIT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>
#include "qeditor.h"

QT_BEGIN_NAMESPACE

class Ui_SnippetEdit
{
public:
    QGridLayout *gridLayout;
    QListWidget *lwSnippets;
    QLabel *label;
    QEditor *eSnippet;
    QLabel *label_5;
    QLineEdit *leSnippetName;
    QLabel *label_6;
    QLineEdit *leSnippetScope;
    QSpacerItem *verticalSpacer;
    QPushButton *bMoreSnippets;
    QSpacerItem *horizontalSpacer;
    QToolButton *tbDeleteSnippet;
    QToolButton *tbCreateSnippet;

    void setupUi(QWidget *SnippetEdit)
    {
        if (SnippetEdit->objectName().isEmpty())
            SnippetEdit->setObjectName(QString::fromUtf8("SnippetEdit"));
        SnippetEdit->resize(548, 486);
        gridLayout = new QGridLayout(SnippetEdit);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lwSnippets = new QListWidget(SnippetEdit);
        QIcon icon;
        icon.addFile(QString::fromUtf8("new.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(lwSnippets);
        __qlistwidgetitem->setIcon(icon);
        lwSnippets->setObjectName(QString::fromUtf8("lwSnippets"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lwSnippets->sizePolicy().hasHeightForWidth());
        lwSnippets->setSizePolicy(sizePolicy);
        lwSnippets->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(lwSnippets, 0, 0, 4, 5);

        label = new QLabel(SnippetEdit);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label, 0, 5, 1, 1);

        eSnippet = new QEditor(SnippetEdit);
        eSnippet->setObjectName(QString::fromUtf8("eSnippet"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(eSnippet->sizePolicy().hasHeightForWidth());
        eSnippet->setSizePolicy(sizePolicy2);
        eSnippet->setFrameShape(QFrame::StyledPanel);
        eSnippet->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(eSnippet, 1, 5, 1, 2);

        label_5 = new QLabel(SnippetEdit);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(label_5, 2, 5, 1, 1);

        leSnippetName = new QLineEdit(SnippetEdit);
        leSnippetName->setObjectName(QString::fromUtf8("leSnippetName"));
        QSizePolicy sizePolicy4(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(leSnippetName->sizePolicy().hasHeightForWidth());
        leSnippetName->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(leSnippetName, 2, 6, 1, 1);

        label_6 = new QLabel(SnippetEdit);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 3, 5, 1, 1);

        leSnippetScope = new QLineEdit(SnippetEdit);
        leSnippetScope->setObjectName(QString::fromUtf8("leSnippetScope"));

        gridLayout->addWidget(leSnippetScope, 3, 6, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer, 4, 5, 1, 2);

        bMoreSnippets = new QPushButton(SnippetEdit);
        bMoreSnippets->setObjectName(QString::fromUtf8("bMoreSnippets"));

        gridLayout->addWidget(bMoreSnippets, 4, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 2, 1, 1);

        tbDeleteSnippet = new QToolButton(SnippetEdit);
        tbDeleteSnippet->setObjectName(QString::fromUtf8("tbDeleteSnippet"));

        gridLayout->addWidget(tbDeleteSnippet, 4, 1, 1, 1);

        tbCreateSnippet = new QToolButton(SnippetEdit);
        tbCreateSnippet->setObjectName(QString::fromUtf8("tbCreateSnippet"));

        gridLayout->addWidget(tbCreateSnippet, 4, 0, 1, 1);

#ifndef QT_NO_SHORTCUT
        label_5->setBuddy(leSnippetName);
        label_6->setBuddy(leSnippetScope);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(lwSnippets, leSnippetName);
        QWidget::setTabOrder(leSnippetName, leSnippetScope);
        QWidget::setTabOrder(leSnippetScope, tbCreateSnippet);
        QWidget::setTabOrder(tbCreateSnippet, tbDeleteSnippet);
        QWidget::setTabOrder(tbDeleteSnippet, bMoreSnippets);

        retranslateUi(SnippetEdit);

        QMetaObject::connectSlotsByName(SnippetEdit);
    } // setupUi

    void retranslateUi(QWidget *SnippetEdit)
    {
        SnippetEdit->setWindowTitle(QString());

        const bool __sortingEnabled = lwSnippets->isSortingEnabled();
        lwSnippets->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = lwSnippets->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("SnippetEdit", "empty", 0, QApplication::UnicodeUTF8));
        lwSnippets->setSortingEnabled(__sortingEnabled);

        label->setText(QApplication::translate("SnippetEdit", "Edit snippet", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("SnippetEdit", "Name/trigger", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        leSnippetName->setToolTip(QApplication::translate("SnippetEdit", "Enter the name of the code snippet, which will also be its full-text trigger, if enabled.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_6->setText(QApplication::translate("SnippetEdit", "Scope(s)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        leSnippetScope->setToolTip(QApplication::translate("SnippetEdit", "Enter a coma-separated list of languages in which the snippet can be used.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        bMoreSnippets->setText(QApplication::translate("SnippetEdit", "More", 0, QApplication::UnicodeUTF8));
        tbDeleteSnippet->setText(QApplication::translate("SnippetEdit", "-", 0, QApplication::UnicodeUTF8));
        tbCreateSnippet->setText(QApplication::translate("SnippetEdit", "+", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SnippetEdit: public Ui_SnippetEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SNIPPETEDIT_H
