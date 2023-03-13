#ifndef DIALOGADD_H
#define DIALOGADD_H

#include <QDialog>
#include "tablemodel.h"
#include "post.h"
#include "QStringList"
#include <QValidator>



namespace Ui {
class DialogAdd;
}

class DialogAdd : public QDialog
{
    Q_OBJECT

signals:
    //Сигнал для вызова основйно формы
    void addsignal();

public:
    explicit DialogAdd(QWidget *parent = nullptr);
    ~DialogAdd();

    //Метод возвращает строку для добавления в модель
    QStringList strAdd();

private slots:
    //Слот для нажатия кнопки
    void on_pushButtonAdd_clicked();

private:
    Ui::DialogAdd *ui;
    TableModel *Tablemodel;
protected:
    //Перевод ui
    void changeEvent(QEvent *event) override;

};

#endif // DIALOGADD_H
