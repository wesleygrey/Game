#include "gametext.h"
#include <QFont>
#include <QGraphicsTextItem>

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
}
