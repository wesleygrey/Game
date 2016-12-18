#ifndef MOVERS_H
#define MOVERS_H

#include <QGraphicsRectItem>
#include <QObject>

//Abstract class that all non-player movable items will inherit from
class Movers: public QObject, public QGraphicsRectItem {
    Q_OBJECT
public slots:
    virtual void move() = 0;
};

class Bullet: public Movers{
    Q_OBJECT
public:
    Bullet();
public slots:
    virtual void move();
};

class Enemy: public Movers{
    Q_OBJECT
public:
    Enemy();
public slots:
    virtual void move();
};

#endif // MOVERS_H
