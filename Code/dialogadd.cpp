#include "dialogadd.h"
#include "ui_dialogadd.h"

//Конструктор
DialogAdd::DialogAdd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAdd)
{
    ui->setupUi(this);
    ui->lineEdit_Id->setValidator(new QIntValidator(1,10000));
    ui->lineEdit_Workers->setValidator(new QIntValidator(1,10000));
}

// Деструкот
DialogAdd::~DialogAdd()
{
    delete ui;
}

// Возвращает строку для вставки в модель
QStringList DialogAdd::strAdd()
{
    QStringList Readstr;
    Readstr << ui->lineEdit_Id->text();
    Readstr << ui->lineEdit_Name->text();
    Readstr << ui->lineEdit_Index->text();
    Readstr << ui->lineEdit_Adress->text();
    Readstr << ui->lineEdit_Time->text();
    Readstr << ui->lineEdit_Tel->text();
    Readstr << ui->lineEdit_Workers->text();
    return Readstr;
}

// Нажатие на кнопку add
void DialogAdd::on_pushButtonAdd_clicked()
{
    this->strAdd();
    emit addsignal();
    this->close();
    ui->lineEdit_Id->clear();
    ui->lineEdit_Name->clear();
    ui->lineEdit_Index->clear();
    ui->lineEdit_Adress->clear();
    ui->lineEdit_Time->clear();
    ui->lineEdit_Tel->clear();
    ui->lineEdit_Workers->clear();
}

// Перевод ui
void DialogAdd::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::LanguageChange) {
        ui->retranslateUi(this);
    }
}
