#include "dialogabout.h"
#include "ui_dialogabout.h"

//Конструктор
DialogAbout::DialogAbout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAbout)
{
    ui->setupUi(this);
}

// Деструкот
DialogAbout::~DialogAbout()
{
    delete ui;
}

// Нажатие на кнопку back
void DialogAbout::on_pushButtonBack_clicked()
{
    this->close();
    emit firstWindow();
}

// Перевод ui
void DialogAbout::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::LanguageChange) {
        ui->retranslateUi(this);
    }
}
