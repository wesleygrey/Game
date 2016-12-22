#ifndef PLAYER_H
#define PLAYER_H
#include <QObject>
#include <QGraphicsRectItem>

class Player: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    //constructs player of size 100 by 100 pixels
    Player();
public slots:  
    //establishes movement and shooting abilities of the player
    void keyPressEvent(QKeyEvent* event);
    void spawnEnemy();
    void spawnCoin();
};

#endif PLAYER_H
