#include "post.h"

//Конструктор
Post::Post():
    mId(0)
  , mName()
  ,mIndex(0)
  ,mAdress()
  ,mTime()
  ,mTel()
  ,mWorkers(0)
{

}


Post::Post(int Id,
           QString Name,
           int Index,
           QString Adress,
           QString Time,
           QString Tel,
           int Workers):
    mId(Id)
  , mName(Name)
  ,mIndex(Index)
  ,mAdress(Adress)
  ,mTime(Time)
  ,mTel(Tel)
  ,mWorkers(Workers)
{

}

// Деструктор
Post::~Post()
{

}

// Сеттер Id
void Post::setId(int Id)
{
    mId = Id;
}

// Сеттер Name
void Post::setName(QString Name)
{
    mName = Name;
}

// Сеттер Index
void Post::setIndex(int Index)
{
    mIndex = Index;
}

// Сеттер Adress
void Post::setAdress(QString Adress)
{
    mAdress = Adress;
}

// Сеттер Time
void Post::setTime(QString Time)
{
    mTime = Time;
}

// Сеттер Tel
void Post::setTel( QString Tel)
{
    mTel = Tel;
}

void Post::setWorkers(int Workers)
{
    mWorkers = Workers;
}

// Геттер Id
int Post::getId() const
{
    return mId;
}

// Геттер Name
QString Post::getName() const
{
    return mName;
}

// Геттер Index
int Post::getIndex() const
{
    return mIndex;
}

// Геттер Adress
QString Post::getAdress() const
{
    return mAdress;
}

// Геттер Time
QString Post::getTime() const
{
    return mTime;
}

// Геттер Tel
QString Post::getTel() const
{
    return mTel;
}

// Геттер Workers
int Post::getWorkers() const
{
    return mWorkers;
}














