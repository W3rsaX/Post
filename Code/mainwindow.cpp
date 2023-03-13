#include "mainwindow.h"
#include "ui_mainwindow.h"


//Конструктор
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    forms();
    readSettings();
    comboBoxSet();
}

// Деструктор
MainWindow::~MainWindow()
{
    writeSettings();

    delete ui;
}

// Нажатие на кнопку About
void MainWindow::on_pushButtonAbout_clicked()
{
    diag->show();
    this->close();
}

// Коннекты формы
void MainWindow::forms()
{
    diag = new DialogAbout();
    connect(diag, &DialogAbout::firstWindow, this, &MainWindow::show);

    MainFile = new MainWindowFile();
    connect(MainFile, &MainWindowFile::firstWindow, this, &MainWindow::show);

    connect(ui->comboBoxLang, &QComboBox::currentTextChanged,
            this, &MainWindow::changeLang);
}

// Чтение настроек
void MainWindow::readSettings()
{
    QSettings settingsMain("MGSY", "pr-post");
    settingsMain.beginGroup("MainWindowGeometry");
    resize(settingsMain.value("size", QSize(400,500)).toSize());
    move(settingsMain.value("pos", QPoint(200, 200)).toPoint());
    settingsMain.endGroup();
}

// Запись настроек
void MainWindow::writeSettings()
{
    QSettings settingsMain("MGSY", "pr-post");
    settingsMain.beginGroup("MainWindowGeometry");
    settingsMain.setValue("size", size());
    settingsMain.setValue("pos", pos());
    settingsMain.endGroup();
}

// Добавление языков
void MainWindow::comboBoxSet()
{
    ui->comboBoxLang->addItem("English");
    ui->comboBoxLang->addItem("Русский");
    ui->comboBoxLang->addItem("Español");
}

// Нажатие на кнопку открытия
void MainWindow::on_pushButtonOpenfile_clicked()
{
    MainFile->show();
    MainFile->NameWindow();
    this->close();
}

// Смена языка
void MainWindow::changeLang()
{
    QString s,str;
    str = ui->comboBoxLang->currentText();
    if (str == "Русский") s = "ru";
    if (str == "Español") s = "es";
    if (str == "English") s = "en";
    qtLanguageTranslator.load("QtLanguage_" + s, ".");
    qApp->installTranslator(&qtLanguageTranslator);
}

// Перевод ui
void MainWindow::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::LanguageChange) {
        ui->retranslateUi(this);
    }
}
