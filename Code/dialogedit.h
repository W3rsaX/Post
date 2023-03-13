#ifndef DIALOGEDIT_H
#define DIALOGEDIT_H

#include <QDialog>
#include "tablemodel.h"
#include "QStringList"
#include <QValidator>

namespace Ui {
class DialogEdit;
}

class DialogEdit : public QDialog
{
    Q_OBJECT

signals:
    //Сигнал для вызова основйно формы
    void editsignal();

public:
    explicit DialogEdit(QWidget *parent = nullptr);
    ~DialogEdit();

    //Метод возвращает строку для класса Post
    QStringList edit();

    //Метод заполняет lineedit
    void refresh(QStringList Writestr);

private slots:
    //Слот для нажатия кнопки
    void on_pushButtonEdit_clicked();

private:
    Ui::DialogEdit *ui;
protected:
    //Перевод ui
    void changeEvent(QEvent *event) override;
};

#endif // DIALOGEDIT_H
