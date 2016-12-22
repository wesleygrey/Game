#include <QApplication>
#include "game.h"

Game* myGame;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    myGame = new Game();
    myGame->show();
    myGame->displayMainMenu(); //fixed
    //myGame->launchGame();

    return a.exec();
}
