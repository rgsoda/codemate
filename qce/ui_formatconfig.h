/********************************************************************************
** Form generated from reading UI file 'formatconfig.ui'
**
** Created: Wed Nov 17 22:36:48 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMATCONFIG_H
#define UI_FORMATCONFIG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormatConfig
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *m_frame;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *m_selector;
    QTableWidget *m_table;

    void setupUi(QWidget *FormatConfig)
    {
        if (FormatConfig->objectName().isEmpty())
            FormatConfig->setObjectName(QString::fromUtf8("FormatConfig"));
        FormatConfig->resize(539, 383);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FormatConfig->sizePolicy().hasHeightForWidth());
        FormatConfig->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(FormatConfig);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        m_frame = new QFrame(FormatConfig);
        m_frame->setObjectName(QString::fromUtf8("m_frame"));
        m_frame->setFrameShape(QFrame::NoFrame);
        m_frame->setFrameShadow(QFrame::Plain);
        gridLayout = new QGridLayout(m_frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(m_frame);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        m_selector = new QComboBox(m_frame);
        m_selector->setObjectName(QString::fromUtf8("m_selector"));

        gridLayout->addWidget(m_selector, 0, 1, 1, 1);


        verticalLayout->addWidget(m_frame);

        m_table = new QTableWidget(FormatConfig);
        if (m_table->columnCount() < 10)
            m_table->setColumnCount(10);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        m_table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        m_table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        m_table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        m_table->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        m_table->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        m_table->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        m_table->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        m_table->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        m_table->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        m_table->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        m_table->setObjectName(QString::fromUtf8("m_table"));
        sizePolicy.setHeightForWidth(m_table->sizePolicy().hasHeightForWidth());
        m_table->setSizePolicy(sizePolicy);
        m_table->setSelectionMode(QAbstractItemView::NoSelection);
        m_table->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout->addWidget(m_table);


        retranslateUi(FormatConfig);

        QMetaObject::connectSlotsByName(FormatConfig);
    } // setupUi

    void retranslateUi(QWidget *FormatConfig)
    {
        FormatConfig->setWindowTitle(QApplication::translate("FormatConfig", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FormatConfig", "Scheme :", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = m_table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("FormatConfig", "Identifier", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = m_table->horizontalHeaderItem(4);
        ___qtablewidgetitem1->setText(QApplication::translate("FormatConfig", "O", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = m_table->horizontalHeaderItem(6);
        ___qtablewidgetitem2->setText(QApplication::translate("FormatConfig", "W", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FormatConfig: public Ui_FormatConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMATCONFIG_H
