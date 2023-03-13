#ifndef DIALOGDEL_H
#define DIALOGDEL_H

#include <QDialog>
#include "tablemodel.h"
#include <QValidator>

namespace Ui {
class DialogDel;
}

class DialogDel : public QDialog
{
    Q_OBJECT

signals:
    //Сигнал для вызова основйно формы
    void delsignal();
public:
    explicit DialogDel(QWidget *parent = nullptr);
    ~DialogDel();

    //Возвращает номер строки для удаления
    int del();

    //Обновление данных для spinbox
    void refreshBox(int k);

private slots:
    //Слот для нажатия кнопки
    void on_pushButtonDelete_clicked();

private:
    Ui::DialogDel *ui;
protected:
    //Перевод ui
    void changeEvent(QEvent *event) override;
};

#endif // DIALOGDEL_H
