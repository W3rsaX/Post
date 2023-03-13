/********************************************************************************
** Form generated from reading UI file 'dialogadd.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGADD_H
#define UI_DIALOGADD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_DialogAdd
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonAdd;
    QSpacerItem *horizontalSpacer_2;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit_Id;
    QLabel *label_2;
    QLineEdit *lineEdit_Name;
    QLabel *label_3;
    QLineEdit *lineEdit_Index;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_Time;
    QLabel *label_6;
    QLineEdit *lineEdit_Tel;
    QLineEdit *lineEdit_Adress;
    QLabel *label_7;
    QLineEdit *lineEdit_Workers;

    void setupUi(QDialog *DialogAdd)
    {
        if (DialogAdd->objectName().isEmpty())
            DialogAdd->setObjectName(QString::fromUtf8("DialogAdd"));
        DialogAdd->resize(425, 278);
        gridLayout = new QGridLayout(DialogAdd);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        pushButtonAdd = new QPushButton(DialogAdd);
        pushButtonAdd->setObjectName(QString::fromUtf8("pushButtonAdd"));
        QFont font;
        font.setPointSize(12);
        pushButtonAdd->setFont(font);

        gridLayout->addWidget(pushButtonAdd, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(DialogAdd);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit_Id = new QLineEdit(DialogAdd);
        lineEdit_Id->setObjectName(QString::fromUtf8("lineEdit_Id"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_Id->sizePolicy().hasHeightForWidth());
        lineEdit_Id->setSizePolicy(sizePolicy);
        lineEdit_Id->setMinimumSize(QSize(250, 0));
        lineEdit_Id->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_Id);

        label_2 = new QLabel(DialogAdd);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        lineEdit_Name = new QLineEdit(DialogAdd);
        lineEdit_Name->setObjectName(QString::fromUtf8("lineEdit_Name"));
        sizePolicy.setHeightForWidth(lineEdit_Name->sizePolicy().hasHeightForWidth());
        lineEdit_Name->setSizePolicy(sizePolicy);
        lineEdit_Name->setFont(font);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_Name);

        label_3 = new QLabel(DialogAdd);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        lineEdit_Index = new QLineEdit(DialogAdd);
        lineEdit_Index->setObjectName(QString::fromUtf8("lineEdit_Index"));
        sizePolicy.setHeightForWidth(lineEdit_Index->sizePolicy().hasHeightForWidth());
        lineEdit_Index->setSizePolicy(sizePolicy);
        lineEdit_Index->setFont(font);
        lineEdit_Index->setText(QString::fromUtf8(""));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_Index);

        label_4 = new QLabel(DialogAdd);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(DialogAdd);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        lineEdit_Time = new QLineEdit(DialogAdd);
        lineEdit_Time->setObjectName(QString::fromUtf8("lineEdit_Time"));
        sizePolicy.setHeightForWidth(lineEdit_Time->sizePolicy().hasHeightForWidth());
        lineEdit_Time->setSizePolicy(sizePolicy);
        lineEdit_Time->setFont(font);
        lineEdit_Time->setText(QString::fromUtf8("-"));

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEdit_Time);

        label_6 = new QLabel(DialogAdd);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        lineEdit_Tel = new QLineEdit(DialogAdd);
        lineEdit_Tel->setObjectName(QString::fromUtf8("lineEdit_Tel"));
        sizePolicy.setHeightForWidth(lineEdit_Tel->sizePolicy().hasHeightForWidth());
        lineEdit_Tel->setSizePolicy(sizePolicy);
        lineEdit_Tel->setFont(font);
        lineEdit_Tel->setLayoutDirection(Qt::LeftToRight);
        lineEdit_Tel->setText(QString::fromUtf8("+ () --"));

        formLayout->setWidget(5, QFormLayout::FieldRole, lineEdit_Tel);

        lineEdit_Adress = new QLineEdit(DialogAdd);
        lineEdit_Adress->setObjectName(QString::fromUtf8("lineEdit_Adress"));
        sizePolicy.setHeightForWidth(lineEdit_Adress->sizePolicy().hasHeightForWidth());
        lineEdit_Adress->setSizePolicy(sizePolicy);
        lineEdit_Adress->setFont(font);

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_Adress);

        label_7 = new QLabel(DialogAdd);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        formLayout->setWidget(6, QFormLayout::LabelRole, label_7);

        lineEdit_Workers = new QLineEdit(DialogAdd);
        lineEdit_Workers->setObjectName(QString::fromUtf8("lineEdit_Workers"));
        sizePolicy.setHeightForWidth(lineEdit_Workers->sizePolicy().hasHeightForWidth());
        lineEdit_Workers->setSizePolicy(sizePolicy);
        lineEdit_Workers->setFont(font);

        formLayout->setWidget(6, QFormLayout::FieldRole, lineEdit_Workers);


        gridLayout->addLayout(formLayout, 0, 1, 1, 1);


        retranslateUi(DialogAdd);

        QMetaObject::connectSlotsByName(DialogAdd);
    } // setupUi

    void retranslateUi(QDialog *DialogAdd)
    {
        DialogAdd->setWindowTitle(QCoreApplication::translate("DialogAdd", "Dialog", nullptr));
        pushButtonAdd->setText(QCoreApplication::translate("DialogAdd", "Add", nullptr));
        label->setText(QCoreApplication::translate("DialogAdd", "Id", nullptr));
        lineEdit_Id->setInputMask(QString());
        label_2->setText(QCoreApplication::translate("DialogAdd", "Name", nullptr));
        label_3->setText(QCoreApplication::translate("DialogAdd", "Index", nullptr));
        lineEdit_Index->setInputMask(QCoreApplication::translate("DialogAdd", "000000", nullptr));
        label_4->setText(QCoreApplication::translate("DialogAdd", "Adress", nullptr));
        label_5->setText(QCoreApplication::translate("DialogAdd", "Working Time", nullptr));
        lineEdit_Time->setInputMask(QCoreApplication::translate("DialogAdd", "00-00", nullptr));
        label_6->setText(QCoreApplication::translate("DialogAdd", "Tel", nullptr));
        lineEdit_Tel->setInputMask(QCoreApplication::translate("DialogAdd", "+0 (000) 000-00-00", nullptr));
        label_7->setText(QCoreApplication::translate("DialogAdd", "Amount of workers", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogAdd: public Ui_DialogAdd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGADD_H
