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
    money = new Money;

    myScene->addItem(score);
    myScene->addItem(health);
    myScene->addItem(money);
    health->setPos(0, 25);
    money->setPos(0,50);

    //spwan enemies at regular intervals
    QTimer* eTimer = new QTimer;
    QObject::connect(eTimer, SIGNAL(timeout()), player, SLOT(spawn()));
    eTimer->start(2500);


    show();
}

void Game::showRules()
{
    //clear the scene
    myScene->clear();

    //Create the text for the instructions, set font and position
    QGraphicsTextItem* welcome = new QGraphicsTextItem("Welcome to Upgrader!");
    QFont wFont = QFont("times", 32);
    welcome->setFont(wFont);
    int wxPos = rect().width()/2 - welcome->boundingRect().width()/2 ;
    int wyPos = 20;
    welcome->setPos(wxPos, wyPos);
    myScene->addItem(welcome);

    //create text briefly describing the game and it's controls
    QGraphicsTextItem* intro = new QGraphicsTextItem("Upgrader is a upgrade-based shooter game"
                                                     " in which nearly all\naspects of gameplay are upgradable.");
    QGraphicsTextItem* controls = new QGraphicsTextItem("Use the spacebar to shoot a bullet.\n"
                                                        "Use the arrow keys to move around.");
    QGraphicsTextItem* rule1 = new QGraphicsTextItem("Enemies will spawn at the top of the screen. Shoot and"
                                                     " avoid\nthem. You will lose health if they touch you or get by you.");
    QGraphicsTextItem* rule2 = new QGraphicsTextItem("Coins will spawn at the left. Collect them to buy upgrades.\n"
                                                     "Power-ups will spawn at the right.");
    QGraphicsTextItem* rule3 = new QGraphicsTextItem("There are 5 levels. At the end of each level there is a boss.\n"
                                                     "If you defeat it, you will be prompted to select new upgrades.");
    QGraphicsTextItem* goodLuck = new QGraphicsTextItem("Good luck!");

    //set the font for the texts
    QFont rulesFont = QFont("times", 16);
    intro->setFont(rulesFont);
    controls->setFont(rulesFont);
    rule1->setFont(rulesFont);
    rule2->setFont(rulesFont);
    rule3->setFont(rulesFont);
    goodLuck->setFont(wFont);

    //set positions of the texts
    int rulesxPos= 10;
    int spacing = 25;
    int iyPos = wyPos + welcome->boundingRect().height() + spacing;
    int cyPos = iyPos + intro->boundingRect().height() + spacing;
    int r1yPos = cyPos + controls->boundingRect().height() + spacing;
    int r2yPos = r1yPos + rule1->boundingRect().height() + spacing;
    int r3yPos = r2yPos + rule2->boundingRect().height() + spacing;
    int gLxPos = rect().width()/2 - goodLuck->boundingRect().width()/2;
    int gLyPos = r3yPos + rule3->boundingRect().height() + spacing;

    intro->setPos(rulesxPos, iyPos);
    controls->setPos(rulesxPos, cyPos);
    rule1->setPos(rulesxPos, r1yPos);
    rule2->setPos(rulesxPos, r2yPos);
    rule3->setPos(rulesxPos, r3yPos);
    goodLuck->setPos(gLxPos, gLyPos);

    //add rules to the scene
    myScene->addItem(intro);
    myScene->addItem(controls);
    myScene->addItem(rule1);
    myScene->addItem(rule2);
    myScene->addItem(rule3);
    myScene->addItem(goodLuck);

    //create the back button
    Button* back = new Button("Go Back");
    int bxPos = 10;
    int byPos = 10;
    back->setPos(bxPos, byPos);
    connect(back, SIGNAL(clicked()), this, SLOT(displayMainMenu()));
    myScene->addItem(back);
}

void Game::level_up()
{
    level++;
}

void Game::drawPanel(int x, int y, int width, int height, QColor color, double opacity)
{
    //draw Panel starting at (x,y) with specified width and height
    QGraphicsRectItem* panel = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    myScene->addItem(panel);
}



void Game::gameOver()
{
    level = 0;
    numEnemies = 0;
    //all settings return to original state
    displayGameOverMenu();
}

void Game::displayGameOverMenu()
{
    //get rid of all scene items
    for(size_t i = 0, n = myScene->items().size(); i < n; ++i){
        myScene->items()[i]->setEnabled(false);
    }

    //display game over messages and ask if the user wants to play again or quit
    drawPanel(0,0, sceneWidth, sceneHeight, Qt::black, 0.65);
    drawPanel(sceneWidth/4, sceneHeight/4, sceneWidth/2, sceneHeight/2, Qt::gray, 1);

    QGraphicsTextItem* gameOver = new QGraphicsTextItem;
    gameOver->setFont(QFont("Helvetica", 20, 20));
    gameOver->setPlainText("GAME OVER");
    gameOver->setPos((sceneWidth/2) - (gameOver->boundingRect().width()/2), (sceneHeight/4) + (gameOver->boundingRect().height()));
    myScene->addItem(gameOver);

    Button* again = new Button(QString("Main Menu"));
    again->setPos(((sceneWidth/2) - (again->boundingRect().width()/2)), ((sceneHeight/2) - (again->boundingRect().height())));
    myScene->addItem(again);
    connect(again, SIGNAL(clicked()), this, SLOT(displayMainMenu()));

    Button* quit = new Button(QString("Quit"));
    quit->setPos(((sceneWidth/2) - (quit->boundingRect().width()/2)), ((sceneHeight/2) + (quit->boundingRect().height())));
    myScene->addItem(quit);
    connect(quit, SIGNAL(clicked()), this, SLOT(close()));


}

