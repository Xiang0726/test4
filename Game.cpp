#include"Game.h"
#include"Minion1.h"
#include"Minion2.h"
#include <QGraphicsScene>
#include <QLabel>
#include <Enemy1.h>
#include <Bullet1.h>
#include"Tower.h"
#include"enemyTower1.h"
#include"Minion3.h"
#include"enemyTower2.h"
#include"enemyTower3.h"
#include<QLabel>
#include<QTime>
#include<stdlib.h>
#include"Fog.h"
#include"Minion4.h"
#include"Hero.h"
#include <QApplication>

int Game::a = 0;
int Game::b = 0;
extern Game * game;

Game::Game(){
    qsrand(time(NULL));
    // create scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setScene(scene);

    // create tower
    Tower * t = new Tower();
    t->setPos(0,50);
    enemyTower1 * t1 = new enemyTower1();
    t1->setPos(900,35);
    enemyTower2 * t2 = new enemyTower2();
    t2->setPos(950,275);
    enemyTower3 * t3 = new enemyTower3();
    t3->setPos(900,515);

    // add tower to scene
    scene->addItem(t);
    scene->addItem(t1);
    scene->addItem(t2);
    scene->addItem(t3);

    button = new QPushButton("close");
    scene->addWidget(button);
    connect(button, SIGNAL(clicked()), this, SLOT(test()));

    button1 = new QPushButton("deck1");
    button1 ->setGeometry(50,500,100,100);
    scene->addWidget(button1);
    connect(button1, SIGNAL(clicked()), this, SLOT(chose1()));

    button10 = new QPushButton("deck1");
    button10 ->setGeometry(150,500,100,100);
    scene->addWidget(button10);
    connect(button10, SIGNAL(clicked()), this, SLOT(choose1()));

    hero = new QPushButton("hero");
    hero ->setGeometry(20,500,50,50);
    scene ->addWidget(hero);
    connect(hero,SIGNAL(clicked()),this,SLOT(sethero()));

    connect(appear_timer,SIGNAL(timeout()),this,SLOT(appear()));
    appear_timer->start(0.000000000001);

}





void Game::final_lose(){
   if(b==3){
    scene->clear();
    scenelose = new QGraphicsScene();
    scenelose->setSceneRect(0,0,800,600);
    setScene(scenelose);
    // display lose
    QLabel * lose = new QLabel();
    lose->setText("you lose the idiotic game");
    lose->setGeometry(200,200,200,50);
    scenelose->addWidget(lose);
   }
}

void Game::chose1()
{
    id = 1;
    int aa = qrand()%4+1;
    //delete button1;
    if(aa==1){
        button1 = new QPushButton("deck1");
        button1 ->setGeometry(50,500,100,100);
        scene->addWidget(button1);
        connect(button1, SIGNAL(clicked()), this, SLOT(chose1()));
       }
    if(aa==2){
        button2 = new QPushButton("deck2");
        button2 ->setGeometry(50,500,100,100);
        scene->addWidget(button2);
        connect(button2, SIGNAL(clicked()), this, SLOT(chose2()));
       }
    if(aa==3){
        button3 = new QPushButton("deck3");
        button3 ->setGeometry(50,500,100,100);
        scene->addWidget(button3);
        connect(button3, SIGNAL(clicked()), this, SLOT(chose3()));
       }
    if(aa==4){
        button4 = new QPushButton("deck4");
        button4 ->setGeometry(50,500,100,100);
        scene->addWidget(button4);
        connect(button4, SIGNAL(clicked()), this, SLOT(chose4()));
    }
}

void Game::chose2()
{
    id = 2;
    int aa = qrand()%4+1;
    //delete button2;
    if(aa==1){
        button1 = new QPushButton("deck1");
        button1 ->setGeometry(50,500,100,100);
        scene->addWidget(button1);
        connect(button1, SIGNAL(clicked()), this, SLOT(chose1()));
       }
    if(aa==2){
        button2 = new QPushButton("deck2");
        button2 ->setGeometry(50,500,100,100);
        scene->addWidget(button2);
        connect(button2, SIGNAL(clicked()), this, SLOT(chose2()));
       }
    if(aa==3){
        button3 = new QPushButton("deck3");
        button3 ->setGeometry(50,500,100,100);
        scene->addWidget(button3);
        connect(button3, SIGNAL(clicked()), this, SLOT(chose3()));
       }
    if(aa==4){
        button4 = new QPushButton("deck4");
        button4 ->setGeometry(50,500,100,100);
        scene->addWidget(button4);
        connect(button4, SIGNAL(clicked()), this, SLOT(chose4()));
    }
}

void Game::chose3()
{
    id = 3;
    int aa = qrand()%4+1;
    //delete button3;
    if(aa==1){
        button1 = new QPushButton("deck1");
        button1 ->setGeometry(50,500,100,100);
        scene->addWidget(button1);
        connect(button1, SIGNAL(clicked()), this, SLOT(chose1()));
       }
    if(aa==2){
        button2 = new QPushButton("deck2");
        button2 ->setGeometry(50,500,100,100);
        scene->addWidget(button2);
        connect(button2, SIGNAL(clicked()), this, SLOT(chose2()));
       }
    if(aa==3){
        button3 = new QPushButton("deck3");
        button3 ->setGeometry(50,500,100,100);
        scene->addWidget(button3);
        connect(button3, SIGNAL(clicked()), this, SLOT(chose3()));
       }
    if(aa==4){
        button4 = new QPushButton("deck4");
        button4 ->setGeometry(50,500,100,100);
        scene->addWidget(button4);
        connect(button4, SIGNAL(clicked()), this, SLOT(chose4()));
    }
}

void Game::chose4()
{
    id = 4;
    int aa = qrand()%4+1;
    //delete button4;
    if(aa==1){
        button1 = new QPushButton("deck1");
        button1 ->setGeometry(50,500,100,100);
        scene->addWidget(button1);
        connect(button1, SIGNAL(clicked()), this, SLOT(chose1()));
       }
    if(aa==2){
        button2 = new QPushButton("deck2");
        button2 ->setGeometry(50,500,100,100);
        scene->addWidget(button2);
        connect(button2, SIGNAL(clicked()), this, SLOT(chose2()));
       }
    if(aa==3){
        button3 = new QPushButton("deck3");
        button3 ->setGeometry(50,500,100,100);
        scene->addWidget(button3);
        connect(button3, SIGNAL(clicked()), this, SLOT(chose3()));
       }
    if(aa==4){
        button4 = new QPushButton("deck4");
        button4 ->setGeometry(50,500,100,100);
        scene->addWidget(button4);
        connect(button4, SIGNAL(clicked()), this, SLOT(chose4()));
    }
}

void Game::choose1()
{
    id = 1;
    int bb = qrand()%4+1;
    //delete button1;
    if(bb==1){
        button10 = new QPushButton("deck1");
        button10->setGeometry(150,500,100,100);
        scene->addWidget(button10);
        connect(button10, SIGNAL(clicked()), this, SLOT(choose1()));
       }
    if(bb==2){
        button20 = new QPushButton("deck2");
        button20 ->setGeometry(150,500,100,100);
        scene->addWidget(button20);
        connect(button20, SIGNAL(clicked()), this, SLOT(choose2()));
       }
    if(bb==3){
        button30 = new QPushButton("deck3");
        button30 ->setGeometry(150,500,100,100);
        scene->addWidget(button30);
        connect(button30, SIGNAL(clicked()), this, SLOT(choose3()));
       }
    if(bb==4){
        button40 = new QPushButton("deck4");
        button40 ->setGeometry(150,500,100,100);
        scene->addWidget(button40);
        connect(button40, SIGNAL(clicked()), this, SLOT(choose4()));
    }
}

void Game::choose2()
{
    id = 2;
    int bb = qrand()%4+1;
    //delete button2;
    if(bb==1){
        button10 = new QPushButton("deck1");
        button10 ->setGeometry(150,500,100,100);
        scene->addWidget(button10);
        connect(button10, SIGNAL(clicked()), this, SLOT(choose1()));
       }
    if(bb==2){
        button20 = new QPushButton("deck2");
        button20 ->setGeometry(150,500,100,100);
        scene->addWidget(button20);
        connect(button20, SIGNAL(clicked()), this, SLOT(choose2()));
       }
    if(bb==3){
        button30 = new QPushButton("deck3");
        button30 ->setGeometry(150,500,100,100);
        scene->addWidget(button30);
        connect(button30, SIGNAL(clicked()), this, SLOT(choose3()));
       }
    if(bb==4){
        button40 = new QPushButton("deck4");
        button40 ->setGeometry(150,500,100,100);
        scene->addWidget(button40);
        connect(button40, SIGNAL(clicked()), this, SLOT(choose4()));
    }
}

void Game::choose3()
{
    id = 3;
    int bb = qrand()%4+1;
    //delete button3;
    if(bb==1){
        button10 = new QPushButton("deck1");
        button10 ->setGeometry(150,500,100,100);
        scene->addWidget(button10);
        connect(button10, SIGNAL(clicked()), this, SLOT(choose1()));
       }
    if(bb==2){
        button20 = new QPushButton("deck2");
        button20 ->setGeometry(150,500,100,100);
        scene->addWidget(button20);
        connect(button20, SIGNAL(clicked()), this, SLOT(choose2()));
       }
    if(bb==3){
        button30 = new QPushButton("deck3");
        button30 ->setGeometry(150,500,100,100);
        scene->addWidget(button30);
        connect(button30, SIGNAL(clicked()), this, SLOT(choose3()));
       }
    if(bb==4){
        button40 = new QPushButton("deck4");
        button40 ->setGeometry(150,500,100,100);
        scene->addWidget(button40);
        connect(button40, SIGNAL(clicked()), this, SLOT(choose4()));
    }
}

void Game::choose4()
{
    id = 4;
    int bb = qrand()%4+1;
    //delete button4;
    if(bb==1){
        button10 = new QPushButton("deck1");
        button10 ->setGeometry(150,500,100,100);
        scene->addWidget(button10);
        connect(button10, SIGNAL(clicked()), this, SLOT(choose1()));
       }
    if(bb==2){
        button20 = new QPushButton("deck2");
        button20 ->setGeometry(150,500,100,100);
        scene->addWidget(button20);
        connect(button20, SIGNAL(clicked()), this, SLOT(choose2()));
       }
    if(bb==3){
        button30 = new QPushButton("deck3");
        button30 ->setGeometry(150,500,100,100);
        scene->addWidget(button30);
        connect(button30, SIGNAL(clicked()), this, SLOT(choose3()));
       }
    if(bb==4){
        button40 = new QPushButton("deck4");
        button40 ->setGeometry(150,500,100,100);
        scene->addWidget(button40);
        connect(button40, SIGNAL(clicked()), this, SLOT(choose4()));
    }
}


void Game::test()
{
   test1 = new QGraphicsScene();
   test1->setSceneRect(0,0,800,600);
   setScene(test1);
}

void Game::final_win(){
    if(a==3){
            // clear scene and reset a new scene
            scene->clear();
            scenewin = new QGraphicsScene();
            scenewin->setSceneRect(0,0,800,600);
            setScene(scenewin);

            // display win
            QLabel * win = new QLabel();
            win->setText("you win the idiotic game");
            win->setGeometry(200,200,200,50);
            scenewin->addWidget(win);
            }
}

void Game::appear(){
    int x1 = qrand()%450+350;
    int y1 = qrand()%600;
    int x2 = qrand()%450+350;
    int y2 = qrand()%600;
    fog * f1 = new fog();
    fog * f2 = new fog();
    f1 ->setPos(x1,y1);
    scene ->addItem(f1);
    f2 ->setPos(x2,y2);
    scene ->addItem(f2);
}

void Game::sethero()
{
    Hero * hero = new Hero();
    hero ->setPos(100,400);
    scene->addItem(hero);
    hero ->setFlag(QGraphicsPixmapItem::ItemIsFocusable);
    hero ->setFocus();

}

void Game::mousePressEvent(QMouseEvent *event){

    if(id == 1){
    // create minion1
    Minion1 * minion = new Minion1();
    minion->setPos(event->x()-250,event->y());
    scene->addItem(minion);
    }
    else if(id == 2){
    // create minion2
    Minion2 * minion = new Minion2();
    minion->setPos(event->x()-250,event->y());
    scene->addItem(minion);
    }
    if(id == 3){
    // create a minion3
    Minion3 * minion = new Minion3();
    minion->setPos(event->x()-250,event->y());
    scene->addItem(minion);
    }
    if(id == 4){
    // create a minion4
    Minion4 * minion = new Minion4();
    minion->setPos(event->x()-250,event->y());
    scene->addItem(minion);
    }
    if(id == 5){
    // create a ENEMY1
    Enemy1 * minion = new Enemy1();
    minion->setPos(event->x()-250,event->y());
    scene->addItem(minion);
    }
    id = 0;
}


