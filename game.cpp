#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QList>
#include "movers.h"
#include "gametext.h"
#include "choosers.h"

Game::Game(QWidget *parent){

    //set sizes of view
    //set view size first so scene can reference view's coordinates for its first 2 parameters
    setFixedSize(800,800);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //create a scene
    myScene = new QGraphicsScene();
    myScene->setSceneRect(0,0,800,800);

    setScene(myScene);

}

void Game::displayMainMenu()
{
    //myScene->clear();

    QGraphicsTextItem* gameTitle = new QGraphicsTextItem(QString("UPGRADER"));
    QFont titleFont("times", 32);
    gameTitle->setFont(titleFont);
    int txPos = rect().width()/2 - gameTitle->boundingRect().width()/2;
    int tyPos = 150;
    gameTitle->setPos(txPos, tyPos);
    myScene->addItem(gameTitle);

    Button* play = new Button(QString("Play"));
    int pxPos = this->width()/2 - play->boundingRect().width()/2;
    int pyPos = 400;
    play->setPos(pxPos, pyPos);
    connect(play, SIGNAL(clicked()), this, SLOT(launchGame()));
    myScene->addItem(play);

    /*Button* rules = new Button(QString("How to Play"));
    int rxPos = rect().width()/2 - rules->boundingRect().width()/2;
    int ryPos = 550;
    rules->setPos(pxPos, pyPos);
    connect(rules, SIGNAL(clicked()), this, SLOT(launchGame()));*/

    Button* quit = new Button(QString("Quit"));
    int qxPos = this->width()/2 - quit->boundingRect().width()/2;
    int qyPos = 700;
    quit->setPos(qxPos, qyPos);
    connect(quit, SIGNAL(clicked()), this, SLOT(close()));
    myScene->addItem(quit);
}

void Game::launchGame()
{

    myScene->clear();

    //create a player
    Player* player = new Player();


    myScene->addItem(player);

    //set the position of the player in the lower middle of the view/scene
    player->setPos(width()/2 - player->rect().width()/2,
                   height() - 2*player->rect().height());


    //make the player focusable and focus on it
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //create score and player health displays
    score = new Score;
    health = new Health;

    myScene->addItem(score);
    myScene->addItem(health);
    health->setPos(0, 25);

    //spwan enemies at regular intervals
    QTimer* eTimer = new QTimer;
    QObject::connect(eTimer, SIGNAL(timeout()), player, SLOT(spawn()));
    eTimer->start(2500);


    show();
}

void Game::level_up()
{
    level++;
}
