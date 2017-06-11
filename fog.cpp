#include "fog.h"
#include "Minion1.h"
#include "Minion2.h"
#include "Minion3.h"
#include "Minion4.h"
#include "Game.h"
#include <QPixmap>
#include<QObject>
#include<QGraphicsScene>
#include<QList>

fog::fog()
{
    setPixmap(QPixmap(":images/Fog.jpg"));

    connect(detect_timer,SIGNAL(timeout()),this,SLOT(detect()));
    detect_timer ->start(10);
}

fog::~fog()
{
    detect_timer -> stop();
    delete detect_timer;
}

void fog::detect()
{
    QList<QGraphicsItem *> colliding_items = this -> collidingItems();
    int a = colliding_items.size();
    for(int i = 0;i < a;i++){
        if(dynamic_cast<Minion1*>(colliding_items[i])){
            scene() ->removeItem(this);
            delete this;
            break;
        }
        else if(dynamic_cast<Minion2*>(colliding_items[i])){
            scene() ->removeItem(this);
            delete this;
            break;
        }
        else if(dynamic_cast<Minion3*>(colliding_items[i])){
            scene() ->removeItem(this);
            delete this;
            break;
        }
        else if(dynamic_cast<Minion4*>(colliding_items[i])){
            scene() ->removeItem(this);
            delete this;
            break;

    }
}
}
