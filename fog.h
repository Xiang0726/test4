#ifndef FOG_H
#define FOG_H
#include<QGraphicsPixmapItem>
#include<QGraphicsItem>
#include<QTimer>

class fog:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    fog();
    ~fog();
    QTimer * detect_timer = new QTimer(this);

public slots:
    void detect();



};

#endif // FOG_H
