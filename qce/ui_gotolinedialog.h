/********************************************************************************
** Form generated from reading UI file 'gotolinedialog.ui'
**
** Created: Mon Nov 1 18:36:11 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOTOLINEDIALOG_H
#define UI_GOTOLINEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_GotoDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QSlider *slideLine;
    QSpinBox *spinLine;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *GotoDialog)
    {
        if (GotoDialog->objectName().isEmpty())
            GotoDialog->setObjectName(QString::fromUtf8("GotoDialog"));
        GotoDialog->resize(210, 103);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GotoDialog->sizePolicy().hasHeightForWidth());
        GotoDialog->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(GotoDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(GotoDialog);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label, 0, 0, 1, 2);

        slideLine = new QSlider(GotoDialog);
        slideLine->setObjectName(QString::fromUtf8("slideLine"));
        slideLine->setMinimum(1);
        slideLine->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(slideLine, 1, 0, 1, 1);

        spinLine = new QSpinBox(GotoDialog);
        spinLine->setObjectName(QString::fromUtf8("spinLine"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(spinLine->sizePolicy().hasHeightForWidth());
        spinLine->setSizePolicy(sizePolicy1);
        spinLine->setMinimum(1);

        gridLayout->addWidget(spinLine, 1, 1, 1, 1);

        buttonBox = new QDialogButtonBox(GotoDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::NoButton|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 2);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(spinLine);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(spinLine, slideLine);
        QWidget::setTabOrder(slideLine, buttonBox);

        retranslateUi(GotoDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), GotoDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), GotoDialog, SLOT(reject()));
        QObject::connect(slideLine, SIGNAL(sliderMoved(int)), spinLine, SLOT(setValue(int)));
        QObject::connect(spinLine, SIGNAL(valueChanged(int)), slideLine, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(GotoDialog);
    } // setupUi

    void retranslateUi(QDialog *GotoDialog)
    {
        GotoDialog->setWindowTitle(QApplication::translate("GotoDialog", "Goto line ...", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("GotoDialog", "Select the line you want to go to :", 0, QApplication::UnicodeUTF8));
        spinLine->setPrefix(QApplication::translate("GotoDialog", "line ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GotoDialog: public Ui_GotoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOTOLINEDIALOG_H
