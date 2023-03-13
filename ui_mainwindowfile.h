/********************************************************************************
** Form generated from reading UI file 'mainwindowfile.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWFILE_H
#define UI_MAINWINDOWFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowFile
{
public:
    QAction *actionSave;
    QAction *actionBack;
    QAction *actionOpen_file;
    QAction *actionNew;
    QAction *actionSave_as;
    QAction *actionExit;
    QAction *actionShow;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QCheckBox *checkBoxQuotesMark;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonFind;
    QLineEdit *lineEditFind;
    QLabel *labelColumn;
    QComboBox *comboBoxColumn;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButtonAdd;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonEdit;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButtonDelete;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelMIMETypeCustomTable;
    QComboBox *comboBoxMimeTypeCustomTable;
    QLabel *labelColumnDelimiterCustomTable;
    QComboBox *comboBoxColumnDelimiterCustomTable;
    QLabel *labelRowDelimiterCustomTable;
    QComboBox *comboBoxRowDelimiterCustomTable;
    QSpacerItem *horizontalSpacer_5;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuGraph;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindowFile)
    {
        if (MainWindowFile->objectName().isEmpty())
            MainWindowFile->setObjectName(QString::fromUtf8("MainWindowFile"));
        MainWindowFile->resize(1215, 824);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindowFile->sizePolicy().hasHeightForWidth());
        MainWindowFile->setSizePolicy(sizePolicy);
        MainWindowFile->setMinimumSize(QSize(700, 760));
        actionSave = new QAction(MainWindowFile);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave->setEnabled(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/Icons/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon);
        actionBack = new QAction(MainWindowFile);
        actionBack->setObjectName(QString::fromUtf8("actionBack"));
        actionOpen_file = new QAction(MainWindowFile);
        actionOpen_file->setObjectName(QString::fromUtf8("actionOpen_file"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/Icons/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen_file->setIcon(icon1);
        actionNew = new QAction(MainWindowFile);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/Icons/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon2);
        actionSave_as = new QAction(MainWindowFile);
        actionSave_as->setObjectName(QString::fromUtf8("actionSave_as"));
        actionSave_as->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/Icons/save_as.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_as->setIcon(icon3);
        actionExit = new QAction(MainWindowFile);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/Icons/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon4);
        actionShow = new QAction(MainWindowFile);
        actionShow->setObjectName(QString::fromUtf8("actionShow"));
        actionShow->setEnabled(false);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/img/Icons/Graph.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionShow->setIcon(icon5);
        centralwidget = new QWidget(MainWindowFile);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        checkBoxQuotesMark = new QCheckBox(centralwidget);
        checkBoxQuotesMark->setObjectName(QString::fromUtf8("checkBoxQuotesMark"));
        checkBoxQuotesMark->setEnabled(false);
        checkBoxQuotesMark->setChecked(true);

        gridLayout->addWidget(checkBoxQuotesMark, 4, 0, 1, 1);

        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy1);
        tableView->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setPointSize(12);
        tableView->setFont(font);
        tableView->setDragEnabled(true);
        tableView->setDragDropOverwriteMode(false);
        tableView->setDragDropMode(QAbstractItemView::DragDrop);
        tableView->setGridStyle(Qt::SolidLine);
        tableView->setSortingEnabled(true);
        tableView->horizontalHeader()->setCascadingSectionResizes(false);
        tableView->horizontalHeader()->setMinimumSectionSize(40);
        tableView->horizontalHeader()->setDefaultSectionSize(160);
        tableView->verticalHeader()->setMinimumSectionSize(25);

        gridLayout->addWidget(tableView, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButtonFind = new QPushButton(centralwidget);
        pushButtonFind->setObjectName(QString::fromUtf8("pushButtonFind"));
        pushButtonFind->setFont(font);

        horizontalLayout_2->addWidget(pushButtonFind);

        lineEditFind = new QLineEdit(centralwidget);
        lineEditFind->setObjectName(QString::fromUtf8("lineEditFind"));
        lineEditFind->setFont(font);

        horizontalLayout_2->addWidget(lineEditFind);

        labelColumn = new QLabel(centralwidget);
        labelColumn->setObjectName(QString::fromUtf8("labelColumn"));
        labelColumn->setFont(font);

        horizontalLayout_2->addWidget(labelColumn);

        comboBoxColumn = new QComboBox(centralwidget);
        comboBoxColumn->addItem(QString());
        comboBoxColumn->addItem(QString());
        comboBoxColumn->addItem(QString());
        comboBoxColumn->addItem(QString());
        comboBoxColumn->addItem(QString());
        comboBoxColumn->addItem(QString());
        comboBoxColumn->addItem(QString());
        comboBoxColumn->setObjectName(QString::fromUtf8("comboBoxColumn"));
        comboBoxColumn->setFont(font);

        horizontalLayout_2->addWidget(comboBoxColumn);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 5);
        horizontalLayout_2->setStretch(2, 1);
        horizontalLayout_2->setStretch(3, 2);

        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        pushButtonAdd = new QPushButton(centralwidget);
        pushButtonAdd->setObjectName(QString::fromUtf8("pushButtonAdd"));
        pushButtonAdd->setFont(font);

        horizontalLayout->addWidget(pushButtonAdd);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonEdit = new QPushButton(centralwidget);
        pushButtonEdit->setObjectName(QString::fromUtf8("pushButtonEdit"));
        pushButtonEdit->setFont(font);

        horizontalLayout->addWidget(pushButtonEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButtonDelete = new QPushButton(centralwidget);
        pushButtonDelete->setObjectName(QString::fromUtf8("pushButtonDelete"));
        pushButtonDelete->setFont(font);

        horizontalLayout->addWidget(pushButtonDelete);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        labelMIMETypeCustomTable = new QLabel(centralwidget);
        labelMIMETypeCustomTable->setObjectName(QString::fromUtf8("labelMIMETypeCustomTable"));

        horizontalLayout_3->addWidget(labelMIMETypeCustomTable);

        comboBoxMimeTypeCustomTable = new QComboBox(centralwidget);
        comboBoxMimeTypeCustomTable->setObjectName(QString::fromUtf8("comboBoxMimeTypeCustomTable"));
        comboBoxMimeTypeCustomTable->setCurrentText(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(comboBoxMimeTypeCustomTable);

        labelColumnDelimiterCustomTable = new QLabel(centralwidget);
        labelColumnDelimiterCustomTable->setObjectName(QString::fromUtf8("labelColumnDelimiterCustomTable"));

        horizontalLayout_3->addWidget(labelColumnDelimiterCustomTable);

        comboBoxColumnDelimiterCustomTable = new QComboBox(centralwidget);
        comboBoxColumnDelimiterCustomTable->addItem(QString());
        comboBoxColumnDelimiterCustomTable->addItem(QString());
        comboBoxColumnDelimiterCustomTable->addItem(QString());
        comboBoxColumnDelimiterCustomTable->setObjectName(QString::fromUtf8("comboBoxColumnDelimiterCustomTable"));
        comboBoxColumnDelimiterCustomTable->setEnabled(false);

        horizontalLayout_3->addWidget(comboBoxColumnDelimiterCustomTable);

        labelRowDelimiterCustomTable = new QLabel(centralwidget);
        labelRowDelimiterCustomTable->setObjectName(QString::fromUtf8("labelRowDelimiterCustomTable"));

        horizontalLayout_3->addWidget(labelRowDelimiterCustomTable);

        comboBoxRowDelimiterCustomTable = new QComboBox(centralwidget);
        comboBoxRowDelimiterCustomTable->addItem(QString());
        comboBoxRowDelimiterCustomTable->addItem(QString());
        comboBoxRowDelimiterCustomTable->addItem(QString());
        comboBoxRowDelimiterCustomTable->setObjectName(QString::fromUtf8("comboBoxRowDelimiterCustomTable"));
        comboBoxRowDelimiterCustomTable->setEnabled(false);
        comboBoxRowDelimiterCustomTable->setCurrentText(QString::fromUtf8("CRLF"));

        horizontalLayout_3->addWidget(comboBoxRowDelimiterCustomTable);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        gridLayout->addLayout(horizontalLayout_3, 3, 0, 1, 1);

        MainWindowFile->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindowFile);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1215, 20));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuGraph = new QMenu(menubar);
        menuGraph->setObjectName(QString::fromUtf8("menuGraph"));
        MainWindowFile->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindowFile);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindowFile->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindowFile);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setMovable(true);
        toolBar->setFloatable(true);
        MainWindowFile->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuGraph->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen_file);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_as);
        menuFile->addAction(actionBack);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuGraph->addAction(actionShow);
        toolBar->addAction(actionNew);
        toolBar->addAction(actionOpen_file);
        toolBar->addAction(actionSave);
        toolBar->addSeparator();
        toolBar->addAction(actionShow);

        retranslateUi(MainWindowFile);

        QMetaObject::connectSlotsByName(MainWindowFile);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowFile)
    {
        MainWindowFile->setWindowTitle(QCoreApplication::translate("MainWindowFile", "MainWindow", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindowFile", "Save", nullptr));
        actionBack->setText(QCoreApplication::translate("MainWindowFile", "Back to main menu", nullptr));
        actionOpen_file->setText(QCoreApplication::translate("MainWindowFile", "Open file", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindowFile", "New", nullptr));
        actionSave_as->setText(QCoreApplication::translate("MainWindowFile", "Save as", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindowFile", "Exit", nullptr));
        actionShow->setText(QCoreApplication::translate("MainWindowFile", "Show", nullptr));
        checkBoxQuotesMark->setText(QCoreApplication::translate("MainWindowFile", "Quotes mark", nullptr));
        pushButtonFind->setText(QCoreApplication::translate("MainWindowFile", "Find", nullptr));
        labelColumn->setText(QCoreApplication::translate("MainWindowFile", "Which column", nullptr));
        comboBoxColumn->setItemText(0, QCoreApplication::translate("MainWindowFile", "Id", nullptr));
        comboBoxColumn->setItemText(1, QCoreApplication::translate("MainWindowFile", "Name", nullptr));
        comboBoxColumn->setItemText(2, QCoreApplication::translate("MainWindowFile", "Index", nullptr));
        comboBoxColumn->setItemText(3, QCoreApplication::translate("MainWindowFile", "Adress", nullptr));
        comboBoxColumn->setItemText(4, QCoreApplication::translate("MainWindowFile", "Working Time", nullptr));
        comboBoxColumn->setItemText(5, QCoreApplication::translate("MainWindowFile", "Tel", nullptr));
        comboBoxColumn->setItemText(6, QCoreApplication::translate("MainWindowFile", "Amount of workers", nullptr));

        pushButtonAdd->setText(QCoreApplication::translate("MainWindowFile", "Add", nullptr));
        pushButtonEdit->setText(QCoreApplication::translate("MainWindowFile", "Edit", nullptr));
        pushButtonDelete->setText(QCoreApplication::translate("MainWindowFile", "Delete", nullptr));
        labelMIMETypeCustomTable->setText(QCoreApplication::translate("MainWindowFile", "MIME type:", nullptr));
        labelColumnDelimiterCustomTable->setText(QCoreApplication::translate("MainWindowFile", "Column delimiter:", nullptr));
        comboBoxColumnDelimiterCustomTable->setItemText(0, QCoreApplication::translate("MainWindowFile", "Comma", nullptr));
        comboBoxColumnDelimiterCustomTable->setItemText(1, QCoreApplication::translate("MainWindowFile", "Semicolon", nullptr));
        comboBoxColumnDelimiterCustomTable->setItemText(2, QCoreApplication::translate("MainWindowFile", "Tab", nullptr));

        labelRowDelimiterCustomTable->setText(QCoreApplication::translate("MainWindowFile", "Row delimiter:", nullptr));
        comboBoxRowDelimiterCustomTable->setItemText(0, QCoreApplication::translate("MainWindowFile", "CRLF", nullptr));
        comboBoxRowDelimiterCustomTable->setItemText(1, QCoreApplication::translate("MainWindowFile", "Line Feed (LF)", nullptr));
        comboBoxRowDelimiterCustomTable->setItemText(2, QCoreApplication::translate("MainWindowFile", "Carriage Return (CR)", nullptr));

        menuFile->setTitle(QCoreApplication::translate("MainWindowFile", "File", nullptr));
        menuGraph->setTitle(QCoreApplication::translate("MainWindowFile", "Graph", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindowFile", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowFile: public Ui_MainWindowFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWFILE_H
