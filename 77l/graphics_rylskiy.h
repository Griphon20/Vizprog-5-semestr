#ifndef GRAPHICS_RYLSKIY_H
#define GRAPHICS_RYLSKIY_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QTime>
#include <QTimer>
#include <QMovie>
#include <QLabel>
#include <QString>
#include <QPixmap>
#include <QtWidgets>
#include <QApplication>
#include <QtGui>



class Graphics : public QGraphicsScene
{
    Q_OBJECT;
public:

    Graphics(QObject* parent= nullptr);

    QGraphicsItem* itemCollidesWith(QGraphicsItem* item);
    void Init();
    void setMovie(QMovie *movie);

private:
    QGraphicsRectItem* rect;
    QGraphicsRectItem* walls[4];

    QGraphicsPixmapItem* rocket;
    QGraphicsPixmapItem* life[3];
    QMovie *movie;
    QLabel *label;
    QGraphicsPixmapItem* Fon;
    QGraphicsPixmapItem* rules;
    QGraphicsPixmapItem* prev;
    QGraphicsPixmapItem* win;
    QGraphicsPixmapItem* asteroid[30];
    QGraphicsPixmapItem* bullet;
    QAction *exitAct;
    double x=150,y=150;
    double dx=0, dy=0,ddx=0,ddy=0,angle=0,x_bullet=200,y_bullet=200;
    int b=0;
    int ai=0;
    int score2=0,tempScore=0;
    double ux[20],uy[20],stepx[20],stepy[20];
    int counter=0;int angle2;
    int xp=0,start=0;

    long int score=0;
    float DAGTORAD= 0.017453f;
    bool thrust;
    int rocket_is_set=0;


public slots:
    void Move();
    void Asteroids();
    void Asteroids_init();
    void Update();
    void Bullet_Update();
    void Bullet_Init();
signals:
    void death(long int);

};

#endif // GRAPHICS_RYLSKIY_H
