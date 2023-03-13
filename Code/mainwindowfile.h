#ifndef MAINWINDOWFILE_H
#define MAINWINDOWFILE_H


#include <QMainWindow>
#include <QApplication>
#include <QInputDialog>
#include <QSortFilterProxyModel>
#include <QSettings>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QLibraryInfo>
#include <QCloseEvent>
#include <QtCharts>

#include "tablemodel.h"
#include "dialogadd.h"
#include "dialogdel.h"
#include "post.h"
#include "dialogedit.h"





namespace Ui {
class MainWindowFile;
}

class MainWindowFile : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowFile(QWidget *parent = nullptr);
    ~MainWindowFile();

    // Список со своим классом
    QList<Post *> Mlist;

    // Свой класс
    Post * post;

    // Загрузка файла
    void load();

    // Смена названия файла
    void setCurrentFile(const QString &fileName);

    // Смена имени окна
    void NameWindow();

signals:
    // Сигнал для основной формы
    void firstWindow();

private slots:
    // Слоты для кнопок
    void on_actionOpen_file_triggered();
    void on_pushButtonAdd_clicked();
    void on_pushButtonDelete_clicked();
    void on_pushButtonEdit_clicked();
    void on_pushButtonFind_clicked();
    void on_actionBack_triggered();

    // Слоты для редактирования модели
    void addStr();
    void delRow();
    void editRow();

    //Слоты для вызова диалоговых окон
    void AddRecord();
    void EditRecord();
    void RemoveRecord();

    // Настройка контекстного меню
    void MenuRequested(QPoint pos);

    // Сохранить как
    bool saveAs();

    // Сигнал выбора поля в комбобоксе
    void changeBox();

    // Создание нового окна
    void newFile();

    // Созранение файла
    bool save();
    bool saveFile(const QString &fileName);

    // Загрузка файла
    void loadFile(const QString &fileName);

    // График
    void on_actionShow_triggered();

private:
    Ui::MainWindowFile *ui;
    MainWindowFile *mainfile;
    TableModel *Tablemodel;
    DialogAdd *diagA;
    DialogDel *diagD;
    DialogEdit *diagE;
    QSortFilterProxyModel *proxy;



    // Название файла
    QString currentFileName;

    // Проверка на имя файла
    bool isUntitled;

    // Настройки окна
    void readSettings();
    void writeSettings();

    // Настройка диалоговых окон
    void diagWindows();

    // Настройка функий
    void FuncSetting();

    // Настройка имени окна
    void WindowNameSetting();


protected:
    // Перевод ui
    void changeEvent(QEvent *event) override;

};

#endif // MAINWINDOWFILE_H
