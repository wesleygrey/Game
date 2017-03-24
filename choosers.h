#ifndef CHOOSERS_H
#define CHOOSERS_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

/*class Choosers: public QGraphicsRectItem{
public:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent* press) = 0;
    virtual void hoverEnterEvent(QGraphicsSceneHoverEvent* in)= 0;
    virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent* out) = 0;
};*/

class Button: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Button(QString name, QGraphicsItem* parent=NULL);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent* press);
    virtual void hoverEnterEvent(QGraphicsSceneHoverEvent* in);
    virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent* out);
signals:
    void clicked();
private:
    QGraphicsTextItem* text;
};

//will be implemented for the menu that pops up between levels.
/*class fillBox: public Choosers{

};*/

#endif // CHOOSERS_H
