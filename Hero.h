#ifndef HERO_H
#define HERO_H
#include<QGraphicsPixmapItem>
#include<QGraphicsPolygonItem>
#include<QGraphicsItem>
#include<QTimer>
#include<QPixmap>

class Hero:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Hero(QGraphicsPixmapItem * parent = 0);
    ~Hero();
    void KeyPressEvent(QKeyEvent * event);
    QTimer * life_timer = new QTimer(this);

public slots:

    void dead();
};

#endif // HERO_H
