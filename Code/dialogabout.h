#ifndef DIALOGABOUT_H
#define DIALOGABOUT_H

#include <QDialog>

namespace Ui {
class DialogAbout;
}

class DialogAbout : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAbout(QWidget *parent = nullptr);
    ~DialogAbout();


signals:
    //Сигнал для вызова основной формы
    void firstWindow();

private slots:
    //Слот для нажатия кнопки
    void on_pushButtonBack_clicked();
protected:
    //Перевод ui
    void changeEvent(QEvent *event) override;

private:
    Ui::DialogAbout *ui;
};

#endif // DIALOGABOUT_H
