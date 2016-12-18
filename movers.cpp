#include "movers.h"
#include <QTimer>
#include <stdlib.h>
#include <QList>

extern Game* myGame;

Bullet::Bullet()
{
    setRect(0,0,10,10);
    //connect a timer to the move() member function
    QTimer* bTimer = new QTimer;
    connect(bTimer, SIGNAL(timeout()), this, SLOT(move()));
    bTimer->start(50);
}

void Bullet::move()
{
    //if bullet collides with enemy, delete both enemy and bullet
    QList<QGraphicsItem*> collision = collidingItems();
    for(size_t pos = 0; pos != collision.size(); ++pos){
        if(typeid(*(collision[pos])) == typeid(Enemy)){
            delete collision[pos];
            delete this;
            myGame->score->update();
            return;
        }
    }
    setPos(x(), y() - 10);
}

Enemy::Enemy()
{
    setRect(0,0,50,50);
    int rand_num = rand() % 750;
    setPos(rand_num, 0);
    QTimer* eTimer = new QTimer;
    connect(eTimer, SIGNAL(timeout()), this, SLOT(move()));
    eTimer->start(100);

}

void Enemy::move()
{
    if(pos().y() > 800){
        delete this;
        myGame->health->update();
        return;
    }
    QList<QGraphicsItem*> collision = collidingItems();
    for(size_t pos = 0; pos != collision.size(); ++pos){
        if(typeid(*(collision[pos])) == typeid(Player)){
            delete this;
            myGame->health->update();
            return;
        }
    }
    setPos(x(), y()+5);
}
