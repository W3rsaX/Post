#include "tablemodel.h"

#include <QModelIndex>
#include <QDebug>
#include <QBrush>
#include <QDebug>
#include <QMimeData>
#include <QDrag>
#include <QList>
#include <QStringList>
#include <QApplication>
#include <QMouseEvent>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QStringList>
#include <QStandardItemModel>

int r = -1,c = -1;

// Конструктор
TableModel::TableModel(QObject *parent) : QAbstractTableModel(parent)
  // По умолчанию определяем тип как внутренний тип ячейки таблицы Qt.
  // Это внутренний бинарный MIME тип используемый только в библиотеке Qt
  // для ячеек таблицы
  , currentMimeType("application/x-qabstractitemmodeldatalist")
  // Проинициализируем переменные соответствующими кодами
  , cr('\r')
  , lf('\n')
  , tab('\t')
  , comma(',')
  , semicolon(';')
  , quotes('\"')
  , columnDelimiter{comma, semicolon, tab}
  , currentColumnDelimiter(columnDelimiter[0])
  , rowDelimiter{lf, lf, cr}
  , addCurrentRowDelimiter{cr}
  , currentRowDelimiter{rowDelimiter[0]}
  , thereAreQuotes(true)

{

}

// Определим текущий формат данных MIME
bool TableModel::hasFormat(const QString &format) const
{
    return currentMimeType == format;
}

// Кол. строк
int TableModel::rowCount(const QModelIndex &parent) const
{
    return list.count();
}

// Кол. столбцов
int TableModel::columnCount(const QModelIndex &parent) const
{
    return 7;


}

// Загрузка данных в модель
QVariant TableModel::data(const QModelIndex &index, int role) const
{
    QVariant value;

    switch ( role )
    {
    case Qt::DisplayRole :


    case Qt::EditRole :

    {
        switch (index.column()) {
        case 0: {
            return list.at(index.row())->getId();
        }
        case 1: {
            return list.at(index.row())->getName();

        }
        case 2: {
            return list.at(index.row())->getIndex();

        }
        case 3: {
            return list.at(index.row())->getAdress();

        }
        case 4: {
            return list.at(index.row())->getTime();

        }
        case 5: {
            return list.at(index.row())->getTel();

        }
        case 6: {
            return list.at(index.row())->getWorkers();

        }
        }
    }
        break;
    case Qt::BackgroundRole :
        if(r != -1)

            if ((index.row() == r) && (index.column() == c))
                return QBrush(Qt::red);
    case Qt::TextAlignmentRole :

    {
        switch (index.column()) {
        case 0: {
            return Qt::AlignRight;
        }
        case 1: {
            return Qt::AlignLeft;

        }
        case 2: {
            return Qt::AlignRight;

        }
        case 3: {
            return Qt::AlignLeft;

        }
        case 4: {
            return Qt::AlignRight;

        }
        case 5: {
            return Qt::AlignLeft;

        }
        case 6: {
            return Qt::AlignRight;

        }
        }
    }
    default:
        break;
    }
    return value;
}

// Установка заголовков таблицы
QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole){
        switch (section) {
        case 0:
            return QString(tr("Id"));
        case 1:
            return QString(tr("Name"));
        case 2:
            return QString(tr("Index"));
        case 3:
            return QString(tr("Adress"));
        case 4:
            return QString(tr("Working Time"));
        case 5:
            return QString(tr("Tel"));
        case 6:
            return QString(tr("Amount of workers"));
        }
    }
    if (orientation == Qt::Vertical && role == Qt::DisplayRole){
        return QString::number(section + 1 );
    }
    return QVariant();


}

// Установка флагов
Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{
    if (index.isValid())
        return Qt::ItemIsEnabled | Qt::ItemIsEditable | Qt::ItemIsSelectable |
                Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled;
    else
        return Qt::NoItemFlags;
}

// Удалие строки
void TableModel::deletRow(int ind)
{
    emit layoutAboutToBeChanged();
    list.removeAt(ind);
    emit layoutChanged();
}

// Кол. записей
int TableModel::rowK()
{
    return list.count();
}

// Очистка модели
void TableModel::clear()
{
    int k = list.count();
    for (int i; i<k; i++){
        this->beginResetModel();
        list.removeLast();
        this->endResetModel();
    }
}

// Вызов этого метода задаёт использование типа MIME
void TableModel::setMimeType(const QString &newMimeType)
{
    if (newMimeType == "text/plain" ||
            newMimeType == "text/csv")
        emit enableDelimiterChange(true);
    else
        emit enableDelimiterChange(false);

    currentMimeType = newMimeType;

}

// Обработка измениний в самой таблицы, для присвоения значений в модель
bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    QStringList Readstr;
    QString str;
    if (!index.isValid())
        return false;

    int row = index.row();
    int col = index.column();

    if (role == Qt::EditRole) {

        if (col == 0)
            list.at(row)->setId(value.toUInt());
        if (col == 1)
            list.at(row)->setName(value.toString());
        if (col == 2)
            list.at(row)->setIndex(value.toUInt());
        if (col == 3)
            list.at(row)->setAdress(value.toString());
        if (col == 4)
            list.at(row)->setTime(value.toString());
        if (col == 5)
            list.at(row)->setTel(value.toString());
        if (col == 6)
            list.at(row)->setWorkers(value.toInt());

        return true;
    }

    return false;

}

// Координаты для Поиска
void TableModel::setInd(int row, int col)
{
    emit layoutAboutToBeChanged();
    r = row;
    c = col;
    emit layoutChanged();
}

// Возвращает модель
const QList<Post *> &TableModel::getPost() const
{
    return list;
}

// Устанавливает модель
void TableModel::setPost(const QList<Post *> &newPost)
{
    emit layoutAboutToBeChanged();
    list = newPost;
    emit layoutChanged();
}

// Возвращает значение для D&D
QVariant TableModel::getVal(const QModelIndex &index, const QMap<int, QVariant> &roles)
{
    QVariant k;
    QMap<int, QVariant>::ConstIterator it = roles.begin();
    it++;
    k = it.value();
    return k;

}

// Вставка строки
bool TableModel::insertRows(int row, int count, const QModelIndex &parent)
{
    Post* l = new Post;
    beginInsertRows(QModelIndex(), row,row + count -1);
    for (int i= 0; i< count; i++)
        list.insert(row,l);
    endInsertRows();
    return true;

}

// Вставка столбца
bool TableModel::removeRows(int row, int count, const QModelIndex &parent)
{
    Q_UNUSED(parent);
    if(-1 < row){
        beginRemoveRows(QModelIndex(), row,row + count -1);
        for (int i= 0; i< count; i++)
            this->removeRow(row);
        endRemoveRows();
        return true;
    }
    else
        return false;
}

// Метод, определяющий типы MIME, которые возможно использовать
// для переноса ячеек таблицы
QStringList TableModel::mimeTypes() const
{
    QStringList types;
    types << "application/x-qabstractitemmodeldatalist";
    types << "text/plain";
    types << "text/csv";

    return types;

}

// Метод, отвечающий за вставку перетаскиваемых данных в нашу таблицу
bool TableModel::dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent)
{
    Q_UNUSED(action);
    emit layoutAboutToBeChanged();
    row = parent.row();
    column = parent.column();
    QStringList types = mimeTypes();
    if (types.isEmpty())
        return false;
    QString format = types.at(0);
    if (!data->hasFormat(format))
        return false;
    QByteArray encoded = data->data(format);
    QDataStream stream(&encoded, QIODevice::ReadOnly);

    emit layoutAboutToBeChanged();

    if (data->hasFormat("application/x-qabstractitemmodeldatalist")) {

        if (parent.isValid()) {
            int top = INT_MAX;
            int left = INT_MAX;
            QVector<int> rows, columns;
            QVector<QMap<int, QVariant> > dataa;

            while (!stream.atEnd()) {
                int r, c;
                QMap<int, QVariant> v;
                stream >> r >> c >> v;
                rows.append(r);
                columns.append(c);
                dataa.append(v);
                top = qMin(r, top);
                left = qMin(c, left);
            }

            for (int i = 0; i < dataa.size(); ++i) {
                int r = (rows.at(i) - top) + parent.row();
                int c = (columns.at(i) - left) + parent.column();
                int k =list.count();
                if(r>=k){

                    Post* post = new Post;
                    QStringList Readstr;
                    Readstr << "" << "" << "" << "" << "" << "" << "";
                    post->setId(Readstr[0].toInt());
                    post->setName(Readstr[1]);
                    post->setIndex(Readstr[2].toInt());
                    post->setAdress(Readstr[3]);
                    post->setTime(Readstr[4]);
                    post->setTel(Readstr[5]);
                    post->setWorkers(Readstr[6].toInt());
                    list.append(post);
                }
                QVariant a = getVal(index(r, c), dataa.at(i));

                if(c == 0){
                    list.at(r)->setId(a.toInt());
                }
                if(c == 1){
                    list.at(r)->setName(a.toString());
                }
                if(c == 2){
                    list.at(r)->setIndex(a.toInt());
                }
                if(c == 3){
                    list.at(r)->setAdress(a.toString());
                }
                if(c == 4){
                    list.at(r)->setTime(a.toString());
                }
                if(c== 5){
                    list.at(r)->setTel(a.toString());
                }
                if(c== 6){
                    list.at(r)->setWorkers(a.toInt());
                }
            }
            return true;
        }

    }


    if (data->hasFormat("text/plain")) {
        QStringList strings;
        if (addCurrentRowDelimiter) {
            strings = data->text().split(QString("%1%2").arg(addCurrentRowDelimiter).arg(currentRowDelimiter));
        }
        else
            strings = data->text().split(currentRowDelimiter);

        for (int rowSelected = 0; rowSelected < strings.count(); ++rowSelected) {
            if ((row + rowSelected) >= rowCount(parent))
                insertRows(list.count(), 1, parent);
            QStringList tokens = strings[rowSelected].split(currentColumnDelimiter);
            for (int columnSelected = 0; columnSelected < tokens.count(); ++columnSelected) {
                QString token = tokens[columnSelected];
                if (thereAreQuotes)
                    token.remove(quotes);
                if (token.isEmpty())
                    continue;
                if(column + columnSelected == 0){
                    list.at(row + rowSelected)->setId(token.toInt());
                }
                if(column + columnSelected == 1){
                    list.at(row + rowSelected)->setName(token);
                }
                if(column + columnSelected == 2){
                    list.at(row + rowSelected)->setIndex(token.toInt());
                }
                if(column + columnSelected == 3){
                    list.at(row + rowSelected)->setAdress(token);
                }
                if(column + columnSelected == 4){
                    list.at(row + rowSelected)->setTime(token);
                }
                if(column + columnSelected == 5){
                    list.at(row + rowSelected)->setTel(token);
                }
                if(column + columnSelected == 6){
                    list.at(row + rowSelected)->setWorkers(token.toInt());
                }
            }
        }

        return true;
    }

    return false;
    emit layoutChanged();
}

// Устанавливает текущий разделитель для строк
void TableModel::setRowDelimiter(int newDelimiter)
{
    if (newDelimiter == 0)
        addCurrentRowDelimiter = cr;
    else
        addCurrentRowDelimiter = '\0';
    currentRowDelimiter = rowDelimiter[newDelimiter];
}

// Устанавливает текущий разделитель для столбцов
void TableModel::setColumnDelimiter(int newDelimiter)
{
    currentColumnDelimiter = columnDelimiter[newDelimiter];
}

// Устанавливает использование кавычек
void TableModel::setQuotes(bool state)
{
    thereAreQuotes = state;
}






QMimeData *TableModel::mimeData(const QModelIndexList &indexes) const
{


    /*if (indexes.isEmpty())
        return nullptr;*/

    // Проверяем первую запись списка на наличие данных по указателю и,
    // если их нет, значит ячейка в таблице отсутствует,
    // а значит дальнейшая работа невозможна и пользователь не сможет
    // выбрать ячейку в таблице.
    // В качестве другого решения, можно было бы отправлять пустой mimeData.
    // Тогда можно было бы копировать несуществующую ячейку.

    // Пример другого решения
    // QMimeData *mimeData = new QMimeData;
    // mimeData->setText("");
    // return mimeData;


    // Сделаем возможность выбора типа MIME данных при реализации
    // операции "Взять и перетащить".
    /*QStringList types = mimeTypes();
    if (types.isEmpty())
        return nullptr;*/


    // Есть возможно работы с диапазонами ячеек в таблице,
    // которые выделил пользователь.
    // Для этого можно воспользоваться функцией selectedRanges().
    // Выделение осуществляется левой клавишей мыши
    // и одновременным зажатием клавиши «Shift» или клавиши «Ctrl».
    // Однако, следует знать одну особенность выделения ячеек через
    // удерживания этих клавиш.
    // Клавиша «Shift» выделяет один непрерывный диапазоны ячеек
    // и методы rowCount() или columnCount() будут возвращать
    // соответствующие количество ячеек,
    // а метод selectedRanges().count() вернёт всего один диапазон.
    // Клавиша «Ctrl» создаёт независимые блоки ячеек по одному элементу
    // и методы rowCount() или columnCount() будут возвращать число ячеек
    // в количестве одной, но диапазонов будет много
    // и метод selectedRanges().count() вернёт диапазонов столько,
    // сколь ячеек было выделено.
    // Ниже представлен пример работы с диапазонами выбранных ячеек
    //    for (int i = 0; i < selectedRanges().count(); ++i) {
    //        rowCount = selectedRanges().at(i).rowCount();
    //        columnCount = selectedRanges().at(i).columnCount();
    //    }

    // Так как под разные типы данных MIME используются разные способы
    // подготовки к передаче данных, то сделаем проверку на тип
    // и в зависимости от входящих значений, будет разный разбор.
    // Типы "text/plain" и "text/csv", представляют из себя одно и тоже,
    // по этому разбираются одним алгоритмом
    if (hasFormat("text/plain") || hasFormat("text/csv") ) {
        QString result;
        int topSelectionRange = indexes.at(0).row();
        int leftSelectionRange = indexes.at(0).column();
        int rowCountSelectionRange = 0;
        int columnCountSelectionRange = 0;
        for (int i = 0; i < indexes.count(); ++i) {



            int c = indexes.at(i).column() - leftSelectionRange;
            int r = indexes.at(i).row() - topSelectionRange;

            if (c > 0 &&
                    (c < columnCountSelectionRange ||
                     indexes.at(i).row() == topSelectionRange))
                result += currentColumnDelimiter;
            if (r > 0 && indexes.at(i).column() == leftSelectionRange) {
                if (addCurrentRowDelimiter)
                    result += addCurrentRowDelimiter;
                result += currentRowDelimiter;
            }
            if (thereAreQuotes)
                result += quotes +
                        indexes.at(i).data(Qt::DisplayRole).toString() +
                        quotes;
            else
                result += indexes.at(i).data(Qt::DisplayRole).toString();

            if (indexes.at(i).row() == topSelectionRange)
                columnCountSelectionRange++;
            if (indexes.at(i).column() == leftSelectionRange)
                rowCountSelectionRange++;
        }
        if (addCurrentRowDelimiter)
            result += addCurrentRowDelimiter;
        result += currentRowDelimiter;
        // Создаём объект формата MIME в который далее сложим обработанные данные.
        // Именно этот объект передаётся другим объектам
        // при перетаскивании указателем мыши.
        QMimeData *mimeData = new QMimeData;

        mimeData->setData(currentMimeType, result.toUtf8());
        return mimeData;
    }

    // Для внутриннего типа Qt алгорит разбора находится в родительском классе
    if (hasFormat("application/x-qabstractitemmodeldatalist")){
        QStringList types = mimeTypes();
        if (types.isEmpty())
            return 0;
        QMimeData *data = new QMimeData();
        QString format = types.at(0);
        QByteArray encoded;
        QDataStream stream(&encoded, QIODevice::WriteOnly);
        encodeData(indexes, stream);
        data->setData(format, encoded);
        return data;
    }
    return nullptr;

}








