/********************************************************************************
** Form generated from reading UI file 'dialogdel.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGDEL_H
#define UI_DIALOGDEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_DialogDel
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_EnterLineNum;
    QSpinBox *spinBox;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButtonDelete;

    void setupUi(QDialog *DialogDel)
    {
        if (DialogDel->objectName().isEmpty())
            DialogDel->setObjectName(QString::fromUtf8("DialogDel"));
        DialogDel->resize(212, 93);
        gridLayout = new QGridLayout(DialogDel);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_EnterLineNum = new QLabel(DialogDel);
        label_EnterLineNum->setObjectName(QString::fromUtf8("label_EnterLineNum"));
        QFont font;
        font.setPointSize(12);
        label_EnterLineNum->setFont(font);

        horizontalLayout->addWidget(label_EnterLineNum);

        spinBox = new QSpinBox(DialogDel);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setFont(font);
        spinBox->setMinimum(1);
        spinBox->setValue(1);

        horizontalLayout->addWidget(spinBox);


        gridLayout->addLayout(horizontalLayout, 1, 1, 1, 2);

        horizontalSpacer = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 3, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 150, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);

        pushButtonDelete = new QPushButton(DialogDel);
        pushButtonDelete->setObjectName(QString::fromUtf8("pushButtonDelete"));
        pushButtonDelete->setFont(font);

        gridLayout->addWidget(pushButtonDelete, 3, 1, 1, 2);


        retranslateUi(DialogDel);

        QMetaObject::connectSlotsByName(DialogDel);
    } // setupUi

    void retranslateUi(QDialog *DialogDel)
    {
        DialogDel->setWindowTitle(QCoreApplication::translate("DialogDel", "Dialog", nullptr));
        label_EnterLineNum->setText(QCoreApplication::translate("DialogDel", "Enter line number", nullptr));
        pushButtonDelete->setText(QCoreApplication::translate("DialogDel", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogDel: public Ui_DialogDel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGDEL_H
