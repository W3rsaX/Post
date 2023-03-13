#ifndef POST_H
#define POST_H

#include <QString>
#include <QObject>

using namespace std;

class Post
{

public:
    //Конструктор
    Post();

    //Операция присваивания
    Post(int Id,
         QString Name,
         int Index,
         QString Adress,
         QString Time,
         QString Tel,
         int Workers);

    //Деструктор
    ~Post();

    //Сеттеры класса
    void setId(int Id);
    void setName(QString Name);
    void setIndex(int Index);
    void setAdress(QString Adress);
    void setTime (QString Time);
    void setTel (QString Tel);
    void setWorkers(int Workers);


    //Геттеры класа
    int getId() const;
    QString getName() const;
    int getIndex() const;
    QString getAdress() const;
    QString getTime() const;
    QString getTel() const;
    int getWorkers() const;

private:
    //Данные
    int mId;
    QString mName;
    int mIndex;
    QString mAdress;
    QString mTime;
    QString mTel;
    int mWorkers;


};

#endif // POST_H
