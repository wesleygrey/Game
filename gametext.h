#ifndef GAMETEXT_H
#define GAMETEXT_H
#include <QGraphicsTextItem>

class GameText: public QGraphicsTextItem {
public slots:
    virtual void update() = 0;
};

class Score: public GameText{
public:
    Score();//QGraphicsTextItem* parent = 0);
public slots:
    virtual void update();
    int getScore();
private:
    int cur_score;
};

class Health: public GameText{
public:
    Health();//QGraphicsTextItem* parent = 0);
public slots:
    virtual void update();
private:
    int cur_health;
};


#endif // GAMETEXT_H
