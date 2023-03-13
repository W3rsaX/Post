#include "dialogedit.h"
#include "ui_dialogedit.h"

//Конструктор
DialogEdit::DialogEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEdit)
{
    ui->setupUi(this);
    ui->lineEditId->setValidator(new QIntValidator(1,10000));
    ui->lineEditWorkers->setValidator(new QIntValidator(1,10000));
}

// Деструкот
DialogEdit::~DialogEdit()
{
    delete ui;
}

// Изменение
QStringList DialogEdit::edit()
{
    QStringList Readstr;
    Readstr << ui->lineEditId->text();
    Readstr << ui->lineEditName->text();
    Readstr << ui->lineEditIndex->text();
    Readstr << ui->lineEditAdress->text();
    Readstr << ui->lineEditTime->text();
    Readstr << ui->lineEditTel->text();
    Readstr << ui->lineEditWorkers->text();
    return Readstr;
}

// Обновление текста в lineedit
void DialogEdit::refresh(QStringList Writestr)
{
    ui->lineEditId->setText(Writestr[0]);
    ui->lineEditName->setText(Writestr[1]);
    ui->lineEditIndex->setText(Writestr[2]);
    ui->lineEditAdress->setText(Writestr[3]);
    ui->lineEditTime->setText(Writestr[4]);
    ui->lineEditTel->setText(Writestr[5]);
    ui->lineEditWorkers->setText(Writestr[6]);
}

// Нажатие на кнопку edit
void DialogEdit::on_pushButtonEdit_clicked()
{
    this->edit();
    emit editsignal();
    this->close();
}

// Перевод ui
void DialogEdit::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::LanguageChange) {
        ui->retranslateUi(this);
    }
}
