#ifndef CHOOSERS_H
#define CHOOSERS_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class Choosers: public QGraphicsRectItem {
public:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent* press) = 0;
    virtual void hoverEnterEvent(QGraphicsSceneHoverEvent* in)= 0;
    virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent* out) = 0;
};

class Button: public Choosers{
public:
    Button(QString* name, QGraphicsRectItem* parent);
signals:
    void clicked();
private:
    QString* text;    
};

class fillBox: public Choosers{
    
};

#endif // CHOOSERS_H
