#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <QTranslator>

#include "mainwindowfile.h"
#include "post.h"
#include "dialogabout.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();




signals:
    //Сигнал для запуска главного окна
    void mainload();

private slots:
    //Слоты для кнопок
    void on_pushButtonAbout_clicked();
    void on_pushButtonOpenfile_clicked();
    //Слот для смены языка
    void changeLang();

private:
    Ui::MainWindow *ui;
    DialogAbout *diag;
    MainWindowFile *MainFile;
    TableModel *Model;
    QTranslator qtLanguageTranslator;

    //Подключение сигнало и слотов
    void forms();
    //Настройки позиции
    void readSettings();
    void writeSettings();
    //Заполнени языков
    void comboBoxSet();


protected:
    //Перевод ui
    void changeEvent(QEvent *event) override;
};
#endif // MAINWINDOW_H
