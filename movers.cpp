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
    if(pos().y() < 0){
        delete this;
        return;
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

Coin::Coin(){
    setRect(0,0,20,20);
    //randomly spawn on the left of the screen
    //no more than 400 pixels above bottom of the screen
    int rand_num = rand() % 680;
    setPos(0, rand_num);
    //connect a timer to the move() member function
    QTimer* cTimer = new QTimer;
    connect(cTimer, SIGNAL(timeout()), this, SLOT(move()));
    cTimer->start(75);
}

void Coin::move()
{
    //if coin leaves view deduct health, delete coin
    if(pos().x() > myGame->sceneWidth){
        delete this;
        return;
    }
    //or if coin collides with player
    QList<QGraphicsItem*> collision = collidingItems();
    for(size_t pos = 0; pos != collision.size(); ++pos){
        if(typeid(*(collision[pos])) == typeid(Player)){
            delete this;
            myGame->money->update();
            return;
        }
    }
    setPos(x()+ 10, y());
}
