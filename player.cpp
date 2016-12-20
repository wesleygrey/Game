#include "player.h"
#include <QKeyEvent>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QDebug>

Player::Player()
{
    setRect(0,0,100,100);
}

void Player::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "Player knows you pressed a key.";
    //qDebug() << "New position is (" << pos().x() << "," << pos().y() << ")";
    if(event->key() == Qt::Key_Left){
        if(pos().x() > 0)
            setPos(x()-5,y());
    }
    else if(event->key() == Qt::Key_Right){
        if(pos().x()+100 < 800)
            setPos(x()+5,y());
    }
    else if(event->key() == Qt::Key_Up){
        if(pos().y() > 0)
            setPos(x(),y()-5);
    }
    else if(event->key() == Qt::Key_Down){
        if(pos().y() + 100 < 800)
            setPos(x(),y()+5);
    }
    else if (event->key() == Qt::Key_Space){
        Bullet* bullet = new Bullet();
        scene()->addItem(bullet);
        bullet->setPos(x() + rect().width()/2 - bullet->rect().width()/2, y());
    }
}

void Player::spawn()
{
    Enemy* nEnemy = new Enemy;
    scene()->addItem(nEnemy);
}
