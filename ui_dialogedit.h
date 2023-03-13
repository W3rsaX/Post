/********************************************************************************
** Form generated from reading UI file 'dialogedit.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGEDIT_H
#define UI_DIALOGEDIT_H

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

class Ui_DialogEdit
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QFormLayout *formLayout;
    QLineEdit *lineEditId;
    QLabel *labelName;
    QLineEdit *lineEditName;
    QLabel *labelIndex;
    QLineEdit *lineEditIndex;
    QLabel *labelAdress;
    QLineEdit *lineEditAdress;
    QLabel *labelTime;
    QLineEdit *lineEditTime;
    QLabel *labelTel;
    QLineEdit *lineEditTel;
    QLabel *labelId;
    QLineEdit *lineEditWorkers;
    QLabel *labelWorkers;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButtonEdit;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QDialog *DialogEdit)
    {
        if (DialogEdit->objectName().isEmpty())
            DialogEdit->setObjectName(QString::fromUtf8("DialogEdit"));
        DialogEdit->resize(425, 290);
        gridLayout = new QGridLayout(DialogEdit);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        lineEditId = new QLineEdit(DialogEdit);
        lineEditId->setObjectName(QString::fromUtf8("lineEditId"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEditId->sizePolicy().hasHeightForWidth());
        lineEditId->setSizePolicy(sizePolicy);
        lineEditId->setMinimumSize(QSize(250, 0));
        QFont font;
        font.setPointSize(12);
        lineEditId->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditId);

        labelName = new QLabel(DialogEdit);
        labelName->setObjectName(QString::fromUtf8("labelName"));
        labelName->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, labelName);

        lineEditName = new QLineEdit(DialogEdit);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));
        lineEditName->setFont(font);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditName);

        labelIndex = new QLabel(DialogEdit);
        labelIndex->setObjectName(QString::fromUtf8("labelIndex"));
        labelIndex->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, labelIndex);

        lineEditIndex = new QLineEdit(DialogEdit);
        lineEditIndex->setObjectName(QString::fromUtf8("lineEditIndex"));
        lineEditIndex->setFont(font);

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEditIndex);

        labelAdress = new QLabel(DialogEdit);
        labelAdress->setObjectName(QString::fromUtf8("labelAdress"));
        labelAdress->setFont(font);

        formLayout->setWidget(3, QFormLayout::LabelRole, labelAdress);

        lineEditAdress = new QLineEdit(DialogEdit);
        lineEditAdress->setObjectName(QString::fromUtf8("lineEditAdress"));
        lineEditAdress->setFont(font);
        lineEditAdress->setText(QString::fromUtf8(""));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEditAdress);

        labelTime = new QLabel(DialogEdit);
        labelTime->setObjectName(QString::fromUtf8("labelTime"));
        labelTime->setFont(font);

        formLayout->setWidget(4, QFormLayout::LabelRole, labelTime);

        lineEditTime = new QLineEdit(DialogEdit);
        lineEditTime->setObjectName(QString::fromUtf8("lineEditTime"));
        lineEditTime->setFont(font);
        lineEditTime->setText(QString::fromUtf8("-"));

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEditTime);

        labelTel = new QLabel(DialogEdit);
        labelTel->setObjectName(QString::fromUtf8("labelTel"));
        labelTel->setFont(font);

        formLayout->setWidget(5, QFormLayout::LabelRole, labelTel);

        lineEditTel = new QLineEdit(DialogEdit);
        lineEditTel->setObjectName(QString::fromUtf8("lineEditTel"));
        lineEditTel->setFont(font);
        lineEditTel->setText(QString::fromUtf8("+ () --"));

        formLayout->setWidget(5, QFormLayout::FieldRole, lineEditTel);

        labelId = new QLabel(DialogEdit);
        labelId->setObjectName(QString::fromUtf8("labelId"));
        labelId->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, labelId);

        lineEditWorkers = new QLineEdit(DialogEdit);
        lineEditWorkers->setObjectName(QString::fromUtf8("lineEditWorkers"));
        lineEditWorkers->setFont(font);

        formLayout->setWidget(6, QFormLayout::FieldRole, lineEditWorkers);

        labelWorkers = new QLabel(DialogEdit);
        labelWorkers->setObjectName(QString::fromUtf8("labelWorkers"));
        labelWorkers->setFont(font);

        formLayout->setWidget(6, QFormLayout::LabelRole, labelWorkers);


        gridLayout->addLayout(formLayout, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 3, 0, 1, 1);

        pushButtonEdit = new QPushButton(DialogEdit);
        pushButtonEdit->setObjectName(QString::fromUtf8("pushButtonEdit"));
        pushButtonEdit->setFont(font);

        gridLayout->addWidget(pushButtonEdit, 3, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 3, 2, 1, 1);


        retranslateUi(DialogEdit);

        QMetaObject::connectSlotsByName(DialogEdit);
    } // setupUi

    void retranslateUi(QDialog *DialogEdit)
    {
        DialogEdit->setWindowTitle(QCoreApplication::translate("DialogEdit", "Dialog", nullptr));
        labelName->setText(QCoreApplication::translate("DialogEdit", "Name", nullptr));
        labelIndex->setText(QCoreApplication::translate("DialogEdit", "Index", nullptr));
        lineEditIndex->setInputMask(QCoreApplication::translate("DialogEdit", "000000", nullptr));
        labelAdress->setText(QCoreApplication::translate("DialogEdit", "Adress", nullptr));
        labelTime->setText(QCoreApplication::translate("DialogEdit", "Working Time", nullptr));
        lineEditTime->setInputMask(QCoreApplication::translate("DialogEdit", "00-00", nullptr));
        labelTel->setText(QCoreApplication::translate("DialogEdit", "Tel", nullptr));
        lineEditTel->setInputMask(QCoreApplication::translate("DialogEdit", "+0 (000) 000-00-00", nullptr));
        labelId->setText(QCoreApplication::translate("DialogEdit", "Id", nullptr));
        labelWorkers->setText(QCoreApplication::translate("DialogEdit", "Amount of workers", nullptr));
        pushButtonEdit->setText(QCoreApplication::translate("DialogEdit", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogEdit: public Ui_DialogEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGEDIT_H
