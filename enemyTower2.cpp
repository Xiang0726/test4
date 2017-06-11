#include"enemyTower2.h"
#include<QPixmap>
#include<QVector>
#include<QPointF>
#include<QPolygonF>
#include"TBullet1.h"
#include"Game.h"
#include<QTimer>
#include<QLineF>
#include <QGraphicsRectItem>
#include"Minion2.h"
#include"Minion1.h"
#include"Minion3.h"
#include "Bullet3.h"
extern Game * game;

enemyTower2::enemyTower2(QGraphicsItem *parent): QObject(),  QGraphicsPixmapItem(parent){

    // set graphics
    setPixmap(QPixmap(":/images/tower.png"));

    //set hp
    hp = 200;

    // craet points vector
    QVector<QPointF> points;
    points << QPointF (1,0) << QPointF (2,0) << QPointF (3,1) << QPointF (3,2) << QPointF (2,3)
           << QPointF (1,3) << QPointF (0,2) << QPointF (0,1);

    //scale
    int scale = 60;
    for(size_t a=0,n=points.size();a<n;a++){
          points[a] = points[a] * scale;
      }

    // create a polygon
    QPolygonF polygon(points);

    // creat the QGraphicPolygonItem
    attack_area = new QGraphicsPolygonItem (polygon,this);

    // move the polygon
    QPointF polygon_center(1.5,1.5);
    polygon_center = polygon_center * scale;
    polygon_center = mapToScene(polygon_center);
    QPointF tower_center (x()+30,y()+55);
    QLineF line(polygon_center,tower_center);
    attack_area->setPos(x()+line.dx(),y()+line.dy());

    // connect a timer to attack_target
    connect(timer,SIGNAL(timeout()),this,SLOT(acquire_target()));
    timer->start(200);

    // connect a timer to dead
    connect(timer,SIGNAL(timeout()),this,SLOT(dead()));
    timerd->start(200);

    // set attack_dest
    attack_dest= QPointF (500,0);
}

double enemyTower2::distance_to(QGraphicsItem *item){
    QLineF line(pos(),item->pos());
    return line.length();
}

void enemyTower2::attack_target(){
   TBullet1 * bullet = new TBullet1();
   bullet->setPos(x(),y());
   QLineF ln(QPointF(x(),y()),QPointF(attack_dest.x()+30,attack_dest.y()+30));
   int angle = -1 * ln.angle();
   bullet->setRotation(angle);
   game->scene->addItem(bullet);
}

enemyTower2::~enemyTower2(){
    // delete timer
    timer->stop();
    delete timer;
    timerd->stop();
    delete timerd;
}

void enemyTower2::dead(){
    if(this->hp <= 0){
        Game::a+=1;
        scene()->removeItem(this);
        delete this;
        game->final_win();
    }
}

void enemyTower2::acquire_target(){
    // get a list of all items colliding with attack_area
    QList<QGraphicsItem *> colliding_items = attack_area->collidingItems();

    if(colliding_items.size() == 1){
        target_exist = false;
        return;
}
    double closest_dist = 300;
    QPointF closest_point = QPointF (0,0);

    for(size_t a =0,n=colliding_items.size(); a<n; a++)
    {
        Minion2 * m2 = dynamic_cast<Minion2 *>(colliding_items[a]);
        Minion1 * m1 = dynamic_cast<Minion1 *>(colliding_items[a]);
        Minion3 * m3 = dynamic_cast<Minion3 *>(colliding_items[a]);
        Bullet1 * b1 = dynamic_cast<Bullet1 *>(colliding_items[a]);
        Bullet3 * b3 = dynamic_cast<Bullet3 *>(colliding_items[a]);

        if(m1){
            double this_list =distance_to(m1);
              if(this_list < closest_dist){
                closest_dist = this_list;
                closest_point = colliding_items[a]->pos();
                target_exist = true;
            }}
   else if(m2){
            double this_list =distance_to(m2);
              if(this_list < closest_dist){
                    closest_dist = this_list;
                    closest_point = colliding_items[a]->pos();
                    target_exist = true;
            }}
   else if(m3){
            double this_list =distance_to(m3);
              if(this_list < closest_dist){
                        closest_dist = this_list;
                        closest_point = colliding_items[a]->pos();
                        target_exist = true;
                    }}
   else if(b1||b3){
            this->hp--;
        }
     }
    attack_dest= closest_point;
    attack_target();
}
