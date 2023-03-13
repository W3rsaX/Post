#include "dialogdel.h"
#include "ui_dialogdel.h"

//Конструктор
DialogDel::DialogDel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDel)
{
    ui->setupUi(this);

}

// Деструкот
DialogDel::~DialogDel()
{
    delete ui;
}

// Возвращает номер строки для удаления
int DialogDel::del()
{

    int k = ui->spinBox->value();
    return k;
}

// Обновление spinbox
void DialogDel::refreshBox(int k)
{
    ui->spinBox->setRange(1, k);
}

// Нажатие на кнопку delet
void DialogDel::on_pushButtonDelete_clicked()
{
    this->del();
    emit delsignal();
    this->close();
}

// Перевод ui
void DialogDel::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::LanguageChange) {
        ui->retranslateUi(this);
    }
}
