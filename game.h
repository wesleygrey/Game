#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include "player.h"
#include "gametext.h"

class Game: public QGraphicsView{
public:
    Game(QWidget* parent=NULL);
    QGraphicsScene* myScene;
    Player* player;
    Score* score;
    Health* health;
public slots:
    void displayMainMenu();
    void launchGame();
    void level_up();
private:
    int level = 0;


};

#endif // GAME_H

