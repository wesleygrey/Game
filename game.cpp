#include "Game.h"
#include <QTimer>

Game::Game(QWidget *parent){
    //create a player
    Player* player = new Player();

    //create a scene and add player
    QGraphicsScene* myScene = new QGraphicsScene();
    myScene->addItem(player);

    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //set sizes of view and screen
    //set view size first so scene can reference view's coordinates for its first 2 parameters
    setFixedSize(800,800);
    myScene->setSceneRect(0,0,800,800);

    //set the position of the player in the lower middle of the view/scene
    player->setPos(width()/2 - player->rect().width()/2,
                   height() - 2*player->rect().height());


    //make the player focusable and focus on it
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    
    //spwan enemies at regular intervals
    QTimer* eTimer = new QTimer;
    QObject::connect(eTimer, SIGNAL(timeout()), player, SLOT(spawn()));
    eTimer->start(2500);

    setScene(myScene);
    show();
    }
