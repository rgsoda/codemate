/********************************************************************************
** Form generated from reading UI file 'gotoline.ui'
**
** Created: Wed Nov 17 22:36:48 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOTOLINE_H
#define UI_GOTOLINE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GotoLine
{
public:
    QHBoxLayout *horizontalLayout;
    QToolButton *bClose;
    QLabel *label;
    QSpinBox *spLine;
    QPushButton *bGo;
    QSlider *slLine;

    void setupUi(QWidget *GotoLine)
    {
        if (GotoLine->objectName().isEmpty())
            GotoLine->setObjectName(QString::fromUtf8("GotoLine"));
        GotoLine->resize(513, 45);
        horizontalLayout = new QHBoxLayout(GotoLine);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        bClose = new QToolButton(GotoLine);
        bClose->setObjectName(QString::fromUtf8("bClose"));

        horizontalLayout->addWidget(bClose);

        label = new QLabel(GotoLine);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        spLine = new QSpinBox(GotoLine);
        spLine->setObjectName(QString::fromUtf8("spLine"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(spLine->sizePolicy().hasHeightForWidth());
        spLine->setSizePolicy(sizePolicy);
        spLine->setMinimum(1);

        horizontalLayout->addWidget(spLine);

        bGo = new QPushButton(GotoLine);
        bGo->setObjectName(QString::fromUtf8("bGo"));

        horizontalLayout->addWidget(bGo);

        slLine = new QSlider(GotoLine);
        slLine->setObjectName(QString::fromUtf8("slLine"));
        slLine->setMinimum(1);
        slLine->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(slLine);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(spLine);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(spLine, bGo);
        QWidget::setTabOrder(bGo, bClose);
        QWidget::setTabOrder(bClose, slLine);

        retranslateUi(GotoLine);

        QMetaObject::connectSlotsByName(GotoLine);
    } // setupUi

    void retranslateUi(QWidget *GotoLine)
    {
        GotoLine->setWindowTitle(QApplication::translate("GotoLine", "Form", 0, QApplication::UnicodeUTF8));
        bClose->setText(QString());
        label->setText(QApplication::translate("GotoLine", "&Go to line :", 0, QApplication::UnicodeUTF8));
        spLine->setPrefix(QString());
        bGo->setText(QApplication::translate("GotoLine", "G&o", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GotoLine: public Ui_GotoLine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOTOLINE_H
