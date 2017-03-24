#include "gametext.h"
#include "game.h"
#include <QFont>
#include <QGraphicsTextItem>

extern Game* myGame;

Score::Score(){//QGraphicsTextItem *parent): QGraphicsTextItem(parent){
    cur_score = 0;
    setPlainText(QString("Score :" + QString::number(cur_score)));
    setDefaultTextColor(Qt::black);
    setFont(QFont("times",16));
}

void Score::update()
{
    cur_score += 100;
    setPlainText(QString("Score :" + QString::number(cur_score)));
}

int Score::getScore()
{
    return cur_score;
}

Health::Health()//QGraphicsTextItem *parent)
{
    cur_health = 100;
    setPlainText(QString("HP :" + QString::number(cur_health)));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));
}

void Health::update()
{
    cur_health -= 10;
    setPlainText(QString("HP :" + QString::number(cur_health)));
    if(cur_health == 0){
        myGame->gameOver();
    }
}

Money::Money()
{
    cur_money = 25;
    setPlainText((QString("Money :" + QString::number(cur_money))));
    setDefaultTextColor(Qt::darkYellow);
    setFont(QFont("times", 16));
}

void Money::update()
{
    cur_money += 5;
    setPlainText(QString("Money :" + QString::number(cur_money)));
}
