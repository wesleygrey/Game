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
    Money* money;
    //this will be the height and width of the scene in pixels
    const int sceneWidth = 800;
    const int sceneHeight = 700;
public slots:
    void displayMainMenu();
    void launchGame();
    void showRules();
    void level_up();
private:
    int level = 0;
};

#endif // GAME_H

