/********************************************************************************
** Form generated from reading UI file 'dialoggraph.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGGRAPH_H
#define UI_DIALOGGRAPH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_DialogGraph
{
public:

    void setupUi(QDialog *DialogGraph)
    {
        if (DialogGraph->objectName().isEmpty())
            DialogGraph->setObjectName(QString::fromUtf8("DialogGraph"));
        DialogGraph->resize(460, 382);

        retranslateUi(DialogGraph);

        QMetaObject::connectSlotsByName(DialogGraph);
    } // setupUi

    void retranslateUi(QDialog *DialogGraph)
    {
        DialogGraph->setWindowTitle(QCoreApplication::translate("DialogGraph", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogGraph: public Ui_DialogGraph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGGRAPH_H
