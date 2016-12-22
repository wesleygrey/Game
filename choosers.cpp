#include "choosers.h"
#include <QGraphicsTextItem>
#include <QBrush>

Button::Button(QString *name, QGraphicsRectItem *parent): QGraphicsRectItem(parent){
    setRect(0,0, 500, 400);
    QBrush bColor;
    bColor.setStyle(Qt::SolidPattern);
    bColor.setColor(Qt::darkRed);
    setBrush(bColor);

    QGraphicsTextItem* bText = new QGraphicsTextItem(name, this);
    int txPos = rect().width()/2 - bText->boundingRect().width()/2;
    int tyPos = rect().height()/2 - bText->boundingRect().height()/2;
    bText->setPos(txPos, tyPos);

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
    bColor.setColor(Qt::darkCyan);
    setBrush(bColor);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *out)
{
    QBrush bColor;
    bColor.setStyle(Qt::SolidPattern);
    bColor.setColor(Qt::darkRed);
    setBrush(bColor);
}
