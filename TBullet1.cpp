#include <QPixmap>
#include <QTimer>
#include <qmath.h> // qSin, qCos, qTan
#include "Game.h"
#include <QLine>
#include <QList>
#include"TBullet1.h"
#include"Minion3.h"

extern Game * game;

TBullet1::TBullet1(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent){

    // set graphics
    setPixmap(QPixmap(":images/bullet.jpg"));

    // connect a timer to move()
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(10);
}

TBullet1::~TBullet1(){
    // delete timer
    move_timer->stop();
    delete move_timer;
}

void TBullet1::move(){
    double slope = 4;
    double theta = rotation();
    double dy = slope * qSin(qDegreesToRadians(theta));
    double dx = slope * qCos(qDegreesToRadians(theta));
    this->setPos(x()+dx,y()+dy);

    // delete after collide with enemy
    QList <QGraphicsItem*>coenemy = this -> collidingItems();
    int a = coenemy.size();
    for(int i = 0;i<a;i++){
        if(typeid(*(coenemy[i])) == typeid(Minion1)||typeid(*(coenemy[i])) == typeid(Minion2)||typeid(*(coenemy[i])) == typeid(Minion3)||this->x()>1200||this->x()<0){

              scene() -> removeItem(this);
              delete this;
              break;
          }
      }
}
