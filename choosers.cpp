#include "choosers.h"
#include <QGraphicsTextItem>
#include <QBrush>
#include <QDebug>

Button::Button(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent){

    setRect(0,0, 100, 50);
    //qDebug() << "rect set";
    QBrush bColor;
    bColor.setStyle(Qt::SolidPattern);
    bColor.setColor(Qt::darkCyan);
    setBrush(bColor);
    qDebug() << "color set";

    QGraphicsTextItem* bText = new QGraphicsTextItem(name, this);
    qDebug() << "name created";
    int txPos = rect().width()/2 - bText->boundingRect().width()/2;
    int tyPos = rect().height()/2 - bText->boundingRect().height()/2;
    bText->setPos(txPos, tyPos);
    qDebug() << "name set";

    setAcceptHoverEvents(true);
}


void Button::mousePressEvent(QGraphicsSceneMouseEvent *press)
{
  emit clicked();
}


void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *in)
{
    QBrush bColor;
    bColor.setStyle(Qt::SolidPattern);
    bColor.setColor(Qt::darkYellow);
    setBrush(bColor);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *out)
{
    QBrush bColor;
    bColor.setStyle(Qt::SolidPattern);
    bColor.setColor(Qt::darkCyan);
    setBrush(bColor);
}
