/********************************************************************************
** Form generated from reading UI file 'editconfig.ui'
**
** Created: Wed Nov 17 22:36:48 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITCONFIG_H
#define UI_EDITCONFIG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFontComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditorConfig
{
public:
    QVBoxLayout *vboxLayout;
    QGroupBox *gbFont;
    QGridLayout *gridLayout;
    QFontComboBox *cbFont;
    QSpinBox *spnFontSize;
    QLabel *lblSampleText;
    QSpacerItem *spacerItem;
    QGroupBox *gbTabs;
    QVBoxLayout *vboxLayout1;
    QHBoxLayout *hboxLayout;
    QLabel *lblTabWitdh;
    QSpinBox *spnTabWidth;
    QSpacerItem *spacerItem1;
    QCheckBox *chkShowLeadingWhitespace;
    QCheckBox *chkShowTabsInText;
    QCheckBox *chkShowTrailingWhitespace;
    QCheckBox *chkReplaceTabs;
    QGroupBox *gbEncodings;
    QGridLayout *gridLayout1;
    QLabel *label;
    QComboBox *cbEncoding;
    QCheckBox *chkDetectLE;
    QComboBox *cbLineEndings;
    QCheckBox *chkAutoRemoveTrailingWhitespace;
    QCheckBox *chkPreserveTrailingIndent;
    QSpacerItem *spacerItem2;

    void setupUi(QWidget *EditorConfig)
    {
        if (EditorConfig->objectName().isEmpty())
            EditorConfig->setObjectName(QString::fromUtf8("EditorConfig"));
        EditorConfig->resize(575, 586);
        vboxLayout = new QVBoxLayout(EditorConfig);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        gbFont = new QGroupBox(EditorConfig);
        gbFont->setObjectName(QString::fromUtf8("gbFont"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(gbFont->sizePolicy().hasHeightForWidth());
        gbFont->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(gbFont);
        gridLayout->setContentsMargins(4, 4, 4, 4);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        cbFont = new QFontComboBox(gbFont);
        cbFont->setObjectName(QString::fromUtf8("cbFont"));
        QFont font;
        font.setFamily(QString::fromUtf8("Monospace"));
        cbFont->setFont(font);
        QFont font1;
        font1.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        cbFont->setCurrentFont(font1);

        gridLayout->addWidget(cbFont, 0, 0, 1, 1);

        spnFontSize = new QSpinBox(gbFont);
        spnFontSize->setObjectName(QString::fromUtf8("spnFontSize"));
        spnFontSize->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spnFontSize->setMinimum(6);
        spnFontSize->setMaximum(50);
        spnFontSize->setValue(10);

        gridLayout->addWidget(spnFontSize, 0, 1, 1, 1);

        lblSampleText = new QLabel(gbFont);
        lblSampleText->setObjectName(QString::fromUtf8("lblSampleText"));
        sizePolicy.setHeightForWidth(lblSampleText->sizePolicy().hasHeightForWidth());
        lblSampleText->setSizePolicy(sizePolicy);
        lblSampleText->setFont(font);
        lblSampleText->setFrameShape(QFrame::StyledPanel);
        lblSampleText->setFrameShadow(QFrame::Sunken);
        lblSampleText->setAlignment(Qt::AlignCenter);
        lblSampleText->setMargin(0);

        gridLayout->addWidget(lblSampleText, 1, 0, 1, 3);

        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem, 0, 2, 1, 1);


        vboxLayout->addWidget(gbFont);

        gbTabs = new QGroupBox(EditorConfig);
        gbTabs->setObjectName(QString::fromUtf8("gbTabs"));
        sizePolicy.setHeightForWidth(gbTabs->sizePolicy().hasHeightForWidth());
        gbTabs->setSizePolicy(sizePolicy);
        vboxLayout1 = new QVBoxLayout(gbTabs);
        vboxLayout1->setContentsMargins(5, 5, 5, 5);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        lblTabWitdh = new QLabel(gbTabs);
        lblTabWitdh->setObjectName(QString::fromUtf8("lblTabWitdh"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lblTabWitdh->sizePolicy().hasHeightForWidth());
        lblTabWitdh->setSizePolicy(sizePolicy1);

        hboxLayout->addWidget(lblTabWitdh);

        spnTabWidth = new QSpinBox(gbTabs);
        spnTabWidth->setObjectName(QString::fromUtf8("spnTabWidth"));
        spnTabWidth->setValue(4);

        hboxLayout->addWidget(spnTabWidth);

        spacerItem1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem1);


        vboxLayout1->addLayout(hboxLayout);

        chkShowLeadingWhitespace = new QCheckBox(gbTabs);
        chkShowLeadingWhitespace->setObjectName(QString::fromUtf8("chkShowLeadingWhitespace"));
        chkShowLeadingWhitespace->setChecked(true);

        vboxLayout1->addWidget(chkShowLeadingWhitespace);

        chkShowTabsInText = new QCheckBox(gbTabs);
        chkShowTabsInText->setObjectName(QString::fromUtf8("chkShowTabsInText"));
        chkShowTabsInText->setChecked(true);

        vboxLayout1->addWidget(chkShowTabsInText);

        chkShowTrailingWhitespace = new QCheckBox(gbTabs);
        chkShowTrailingWhitespace->setObjectName(QString::fromUtf8("chkShowTrailingWhitespace"));
        chkShowTrailingWhitespace->setChecked(true);

        vboxLayout1->addWidget(chkShowTrailingWhitespace);

        chkReplaceTabs = new QCheckBox(gbTabs);
        chkReplaceTabs->setObjectName(QString::fromUtf8("chkReplaceTabs"));

        vboxLayout1->addWidget(chkReplaceTabs);


        vboxLayout->addWidget(gbTabs);

        gbEncodings = new QGroupBox(EditorConfig);
        gbEncodings->setObjectName(QString::fromUtf8("gbEncodings"));
        gridLayout1 = new QGridLayout(gbEncodings);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        label = new QLabel(gbEncodings);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout1->addWidget(label, 0, 0, 1, 1);

        cbEncoding = new QComboBox(gbEncodings);
        cbEncoding->setObjectName(QString::fromUtf8("cbEncoding"));

        gridLayout1->addWidget(cbEncoding, 0, 1, 1, 1);

        chkDetectLE = new QCheckBox(gbEncodings);
        chkDetectLE->setObjectName(QString::fromUtf8("chkDetectLE"));
        chkDetectLE->setChecked(true);

        gridLayout1->addWidget(chkDetectLE, 1, 0, 1, 1);

        cbLineEndings = new QComboBox(gbEncodings);
        cbLineEndings->setObjectName(QString::fromUtf8("cbLineEndings"));
        cbLineEndings->setEnabled(false);

        gridLayout1->addWidget(cbLineEndings, 1, 1, 1, 1);

        chkAutoRemoveTrailingWhitespace = new QCheckBox(gbEncodings);
        chkAutoRemoveTrailingWhitespace->setObjectName(QString::fromUtf8("chkAutoRemoveTrailingWhitespace"));

        gridLayout1->addWidget(chkAutoRemoveTrailingWhitespace, 2, 0, 1, 1);

        chkPreserveTrailingIndent = new QCheckBox(gbEncodings);
        chkPreserveTrailingIndent->setObjectName(QString::fromUtf8("chkPreserveTrailingIndent"));
        chkPreserveTrailingIndent->setEnabled(false);

        gridLayout1->addWidget(chkPreserveTrailingIndent, 2, 1, 1, 1);


        vboxLayout->addWidget(gbEncodings);

        spacerItem2 = new QSpacerItem(492, 10, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        vboxLayout->addItem(spacerItem2);

#ifndef QT_NO_SHORTCUT
        lblTabWitdh->setBuddy(spnTabWidth);
#endif // QT_NO_SHORTCUT

        retranslateUi(EditorConfig);
        QObject::connect(chkDetectLE, SIGNAL(toggled(bool)), cbLineEndings, SLOT(setDisabled(bool)));
        QObject::connect(chkAutoRemoveTrailingWhitespace, SIGNAL(toggled(bool)), chkPreserveTrailingIndent, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(EditorConfig);
    } // setupUi

    void retranslateUi(QWidget *EditorConfig)
    {
        gbFont->setTitle(QApplication::translate("EditorConfig", "Font", 0, QApplication::UnicodeUTF8));
        lblSampleText->setText(QApplication::translate("EditorConfig", "text which <i>should</i> be a <b>fair</b> test of the font", 0, QApplication::UnicodeUTF8));
        gbTabs->setTitle(QApplication::translate("EditorConfig", "Tabulators && Whitespaces", 0, QApplication::UnicodeUTF8));
        lblTabWitdh->setText(QApplication::translate("EditorConfig", "Tab width", 0, QApplication::UnicodeUTF8));
        chkShowLeadingWhitespace->setText(QApplication::translate("EditorConfig", "Show leading whitespaces", 0, QApplication::UnicodeUTF8));
        chkShowTabsInText->setText(QApplication::translate("EditorConfig", "Show tabs which are neither leading nor trailing", 0, QApplication::UnicodeUTF8));
        chkShowTrailingWhitespace->setText(QApplication::translate("EditorConfig", "Show trailing whitespaces", 0, QApplication::UnicodeUTF8));
        chkReplaceTabs->setText(QApplication::translate("EditorConfig", "Replace tabs by blanks", 0, QApplication::UnicodeUTF8));
        gbEncodings->setTitle(QApplication::translate("EditorConfig", "Load && Save", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("EditorConfig", "Default encoding", 0, QApplication::UnicodeUTF8));
        chkDetectLE->setText(QApplication::translate("EditorConfig", "Preserve line endings", 0, QApplication::UnicodeUTF8));
        cbLineEndings->clear();
        cbLineEndings->insertItems(0, QStringList()
         << QApplication::translate("EditorConfig", "Local", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EditorConfig", "Unix/Linux", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EditorConfig", "DOS/Windows", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EditorConfig", "Old Mac", 0, QApplication::UnicodeUTF8)
        );
        chkAutoRemoveTrailingWhitespace->setText(QApplication::translate("EditorConfig", "Remove trailing spaces", 0, QApplication::UnicodeUTF8));
        chkPreserveTrailingIndent->setText(QApplication::translate("EditorConfig", "Preserve trailing indent", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(EditorConfig);
    } // retranslateUi

};

namespace Ui {
    class EditorConfig: public Ui_EditorConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITCONFIG_H
