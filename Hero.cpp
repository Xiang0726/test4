#include"Hero.h"
#include<QPixmap>
#include<QObject>
#include<QTimer>
#include<QGraphicsScene>
#include<QVector>
#include<QPointF>
#include<QPolygonF>
#include<QLineF>
#include "Game.h"
#include <Bullet1.h>
#include <QList>
#include <Tower.h>
#include "Bullet10.h"
#include"enemyTower1.h"
#include"TBullet1.h"
#include"enemyTower2.h"
#include"enemyTower3.h"
#include <QKeyEvent>
#include<QDebug>

Hero::Hero(QGraphicsPixmapItem *parent)
{
    // draw pic
    setPixmap(QPixmap(":images/EE7.png"));

    connect(life_timer,SIGNAL(timeout()),this,SLOT(dead()));
            life_timer->start(10000);
}

Hero::~Hero()
{
    life_timer->stop();
    delete life_timer;
}

void Hero::KeyPressEvent(QKeyEvent *event)
{
      if (event->key() == Qt::Key_Left){
          qDebug() << "ee" << endl;
          setPos(x()-10,y());
      }
      else if (event->key() == Qt::Key_Right){
          setPos(x()+10,y());
      }
      else if (event->key() == Qt::Key_Up){
          setPos(x(),y()-10);
      }
      else if (event->key() == Qt::Key_Down){
          setPos(x(),y()+10);
      }
}



void Hero::dead()
{
    scene()->removeItem(this);
    delete this;
}
