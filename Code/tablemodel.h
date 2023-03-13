#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
#include "post.h"
#include <QModelIndex>
#include <QTextStream>
#include <QVector>




class Post;

class TableModel : public QAbstractTableModel
{
    Q_OBJECT

    // Переменная ответственная за хранение текущего типа MIME,
    // выбираемого пользователем в comboBoxMimeTypeCustomTable
    QString currentMimeType;

    // Определим несколько символов для разметки
    const char cr;        // Возврат каретки (англ. Carriage Return)(Байт: 0x0d)
    const char lf;        // Перевод на строку (англ. Line Feed) (Байт: 0x0a)
    const char tab;       // Табуляция (Байт: 0x09)
    const char comma;     // Запятая (Байт: 0x2C)
    const char semicolon; // Точка с запятой (Байт: 0x3B)
    const char quotes;    // Кавычки (Байт: 0x22)

    // Возможные варианты разделителя столбцов
    char columnDelimiter[3];
    // Текущий разделитель столбцов
    char currentColumnDelimiter;
    // Основные возможные варианты разделителя строк
    char rowDelimiter[3];
    // Текущий основной разделитель строк
    char addCurrentRowDelimiter;
    // Дополнительный символ для переноса из двух символов
    char currentRowDelimiter;
    // Использовать ли кавычки для обрамления данных в ячейке
    bool thereAreQuotes;

    // Определим текущий формат данных MIME
    bool hasFormat(const QString &format) const;

    //Лист с моделью
    QList<Post *> list;
public:
    explicit TableModel(QObject *parent = nullptr);

    //Задание размером таблицы
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;

    //Данные таблицы
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role) override;

    //Установка флагов
    Qt::ItemFlags flags(const QModelIndex &index) const override;

    //Измение кол. записей
    bool insertRows(int row, int count, const QModelIndex &parent) override;
    bool removeRows(int row, int count, const QModelIndex &parent) override;

    //Устанавливает индекс ячейки
    void setInd(int row, int col);

    //Возвращает модель
    const QList<Post *> &getPost() const;
    //Устанавливает модель
    void setPost(const QList<Post *> &newPost);

    //Возвращает значение для D&D
    QVariant getVal (const QModelIndex &index, const QMap<int, QVariant> &roles);

    //Удаление записи
    void deletRow(int ind);
    //Добавление записи
    void insertRow(int ind, Post value);

    //Возвращает количество записей
    int rowK();

    //Очистка модели
    void clear();



public slots: // Вызов этого метода задаёт использование типа MIME
    void setMimeType(const QString &newMimeType);
    // Устанавливает текущий разделитель для строк
    void setRowDelimiter(int newDelimiter);
    // Устанавливает текущий разделитель для столбцов
    void setColumnDelimiter(int newDelimiter);
    // Устанавливает использование кавычек
    void setQuotes(bool state);

signals:  // Сигнал нужен для установки типа MIME
    void enableDelimiterChange(bool state);




    // QAbstractItemModel interface
public:
    // Метод, определяющий типы MIME, которые возможно использовать
    // для переноса ячеек таблицы
    QStringList mimeTypes() const override;

    // Метод, отвечающий за вставку перетаскиваемых данных в нашу таблицу
    bool dropMimeData(const QMimeData *data, Qt::DropAction action, int row,
                      int column, const QModelIndex &parent) override;
    // Метод mimeData() ответственен за обработку данных ячейки,
    // которую пользователь начал перетаскивать указателем мыши

    QMimeData *mimeData(const QModelIndexList &indexes) const override;






};

#endif // TABLEMODEL_H
