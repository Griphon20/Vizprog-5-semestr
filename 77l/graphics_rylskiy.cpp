#include "graphics_rylskiy.h"
#include <windows.h>
#include <math.h>
#include <ctime>
#include <random>


int TIMER_ASTEROID=50;
int scores=0;
extern QString text;
extern int aa;
void Graphics::Init(){


    QPixmap newImage;


    if (!newImage.load(QStringLiteral("D:\\QT\\77l\\images\\cosmos.png"))) {
        return;
    }
    Fon = addPixmap(newImage);


    Fon->setPos(0, 100);



    if (!newImage.load(QStringLiteral("D:\\QT\\77l\\images\\bb.png"))) {
        return;
    }
    rocket = addPixmap(newImage);
    rocket->setScale(0.15);
    rocket->setPos(100, 100);


    if (!newImage.load(QStringLiteral("D:\\QT\\77l\\images\\Win.png"))) {
        return;
    }

    rules = addPixmap(newImage);
    rules->setPos(5, 105);
    rules->hide();

    if (!newImage.load(QStringLiteral("D:\\QT\\77l\\images\\Lose.png"))) {
        return;
    }

    win = addPixmap(newImage);
    win->setPos(5, 105);
    win->hide();

    label =new QLabel();
    movie = new QMovie("D:\\QT\\77l\\Type_A.gif");
    label->setMovie(movie);
    movie->setSpeed(100);

    label->setAttribute( Qt::WA_TranslucentBackground );
    walls[0] = addRect(QRectF(0,100,10,500),QPen(Qt::black), QBrush(QColor(0, 214, 120)));
    walls[1] = addRect(QRectF(800,100,10,510), QPen(Qt::black), QBrush(QColor(0, 214, 120)));
    walls[2] = addRect(QRectF(0,100,800,10), QPen(Qt::black), QBrush(QColor(0, 214, 120)));
    walls[3] = addRect(QRectF(0,600,800,10), QPen(Qt::black), QBrush(QColor(0, 214, 120)));

    for(int i=0; i<4; i++)
            walls[i]->setData(0,"Wall");


    if (!newImage.load(QStringLiteral("D:\\QT\\77l\\images\\life.png"))) {
        return;
    }

    for(int i=0,k=0; i<3; i++,k+=100){
            life[i] = addPixmap(newImage);
            life[i]->setPos(0+k,0);
            life[i]->setScale(0.15);
            life[i]->setData(0, "life");

        }





}
void Graphics::Bullet_Init(){



       QPixmap newImage;
    if (!newImage.load(QStringLiteral("D:\\QT\\77l\\images\\pula.png")))
        return;
    bullet = addPixmap(newImage);
    bullet->setPos(x,y);
    bullet->setScale(0.4);
    bullet->setData(0, "bullet");
}

void Graphics::Asteroids_init()
{
    QPixmap newImage;
    if (!newImage.load(QStringLiteral("D:\\QT\\77l\\images\\asteroid.png"))) {
        return;
    }
    for(int i=0; i<20; i++){

            asteroid[i] = addPixmap(newImage);
            asteroid[i]->setPos(ux[i],uy[i]);
            asteroid[i]->setScale(0.08);
            asteroid[i]->setData(0, "Asteroid");
            asteroid[i]->setRotation(rand()%90);
            if (ux[i]>690){ ux[i]=100;
           }
                if (ux[i]<90) {ux[i]=670;
               }

            if (uy[i]>490){ uy[i]=110;
           }
            if (uy[i]<90) {uy[i]=480;

          }
        }
    if (!newImage.load(QStringLiteral("D:\\QT\\77l\\images\\newgame.png"))) {
        return;
    }
    prev = addPixmap(newImage);
    prev->setPos(10, 110);

}
void Graphics::Asteroids(){
    ai+=1;
    if(start<1)
    for(int i=0; i<20; i++){
        asteroid[i]->setPos(ux[i],uy[i]);


    }

if(start>2){

   for(int i=0; i<20; i++){

   asteroid[i]->setPos(ux[i],uy[i]);

   ux[i]+=stepx[i];
   uy[i]+=stepy[i];
   if (ux[i]>750){ ux[i]=70;
  }
       if (ux[i]<50) {ux[i]=740;
      }

   if (uy[i]>520){ uy[i]=110;
  }
   if (uy[i]<105) {uy[i]=490;

 }
   }
}

}

void Graphics::Update()
 {

   if (thrust)
    { dx+=cos(angle*DAGTORAD)*0.02;
      dy+=sin(angle*DAGTORAD)*0.02; }
   else
    { dx*=0.99;
      dy*=0.99; }

  int maxSpeed=2;
  float speed = sqrt(dx*dx+dy*dy);
  if (speed>maxSpeed)
   { dx *= maxSpeed/speed;
     dy *= maxSpeed/speed; }
  x+=dx;
  y+=dy;

  if (thrust)
   { ddx+=cos(angle*DAGTORAD)*0.02;
     ddy+=sin(angle*DAGTORAD)*0.02; }
  else
   { ddx*=0.99;
     ddy*=0.99; }

 int maxSpeed2=2;
 float speed2 = sqrt(ddx*ddx+ddy*ddy);
 if (speed2>maxSpeed2)
  { ddx *= maxSpeed2/speed2;
    ddy *= maxSpeed2/speed2; }
  x_bullet+=ddx+cos(angle*DAGTORAD)*10;
  y_bullet+=ddy+sin(angle*DAGTORAD)*10;

  if(counter==0){
      x_bullet=0;
      x_bullet=x;
      y_bullet=0;
      y_bullet=y;}

  ddx=0;
  ddy=0;
  ddx=x_bullet;
  ddy=y_bullet;


  if (x>790){ x=90;
 }
      if (x<10) {x=780;
     }

  if (y>590){ y=130;
 }
  if (y<120) {y=580;

}

  rocket->setPos(x, y);
  rocket->setRotation(angle+90);




  if (counter==0){
     bullet->setPos(1200, 1200);

  }

}


void  Graphics::Bullet_Update()
{


if(GetAsyncKeyState(VK_SPACE)&&start>3){
counter=1;
}

if(counter==1&&start>3) {

      bullet->setPos(ddx,ddy);
      bullet->setRotation(angle+90);


}

}

void Graphics::Move(){

    if(GetAsyncKeyState(VK_RIGHT)) {
    angle+=1;

    }
    if(GetAsyncKeyState(VK_LEFT)){
    angle-=1;
    }

    if(GetAsyncKeyState(VK_UP) ){
    thrust=true;

    }

    else thrust=false;


    Update();

    if(rocket_is_set==1){
       rocket->setPos(130, 130);
       rocket_is_set=0;
    }

if(GetAsyncKeyState(VK_RETURN) ){
    if(text!=""){
start+=4;
b+=5;
for(int i=0; i<20; i++){
        asteroid[i]->show();
    }
prev->hide();
rules->hide();
win->hide();
addRect(QRectF(400,0,300,50),QPen(QColor(255, 255, 255)), QBrush(QColor(255, 255, 255)));
QGraphicsTextItem *text = addText("Очки: " +QString::number(score));
   text->setPos(500, 0);
   text->setDefaultTextColor(QColor(0, 0, 0));
   text->setScale(2.1);}
}
if(GetAsyncKeyState(0x53)){
tempScore=1;

}
    QGraphicsItem* barrier = itemCollidesWith(bullet);

    if(bullet&&start>3){
        if(barrier->data(0)=="Asteroid"&&start>3){

            barrier->setPos(3000,500);
            bullet->setPos(3000,1000);
            barrier->hide();
            Bullet_Init();
            counter=0;
            score+=5;
            scores+=5;
            addRect(QRectF(400,0,300,50),QPen(QColor(255, 255, 255)), QBrush(QColor(255, 255, 255)));
            QGraphicsTextItem *text = addText("Очки: " +QString::number(score));
               text->setPos(500, 0);
               text->setDefaultTextColor(QColor(0, 0, 0));
               text->setScale(2.1);
            if(score>95){
                bullet->setPos(2000,200);
                for(int i=0,k=0; i<3; i++,k+=100){
                        life[i]->setPos(0+k,0);
                        life[i]->setScale(0.15);
                        life[i]->setData(0, "life");

                    }
                for(int i=0; i<20; i++){
                    ux[i]= rand() % 150 + 400;
                    uy[i]=rand() % 150 + 200;
                    stepx[i]=rand()%8-4;
                    stepy[i]=rand()%8-4;

                }
                for(int i=0; i<20; i++){
                        asteroid[i]->show();
                    }
                x=150;
                y=150;
                dx=0, dy=0;
             emit death(score);
                for(int i=0; i<20; i++){
                        asteroid[i]->hide();
                    }
            win->show();
            score =0;
            start=0;
            b=4;

            }

            //label->show();
            //movie->start();
        }

        if(barrier->data(0)=="Wall"){

            bullet->setPos(3000,200);
            Bullet_Init();
            counter=0;
        }




    QGraphicsItem* barrier2 = itemCollidesWith(rocket);

    if(rocket&&start>3){
        if(barrier2->data(0)=="Asteroid"){
            score+=5;
            scores+=5;
            addRect(QRectF(400,0,300,50),QPen(QColor(255, 255, 255)), QBrush(QColor(255, 255, 255)));
            QGraphicsTextItem *text = addText("Очки: " +QString::number(score));
               text->setPos(500, 0);
               text->setDefaultTextColor(QColor(0, 0, 0));
               text->setScale(2.1);
            xp+=1;

           barrier2->hide();
           life[xp-1]->setPos(2000,100);
           if(xp==3){
            rocket_is_set=1;
            angle =0;
            x=150;
            y=150;
            dx=0, dy=0;


            start=-100;
            bullet->setPos(2000,200);
            for(int i=0,k=0; i<3; i++,k+=100){
                    life[i]->setPos(0+k,0);
                    life[i]->setScale(0.15);
                    life[i]->setData(0, "life");

                }
            for(int i=0; i<20; i++){
                ux[i]= rand() % 150 + 400;
                uy[i]=rand() % 150 + 200;
                stepx[i]=rand()%8-4;
                stepy[i]=rand()%8-4;

            }
            for(int i=0; i<20; i++){
                    asteroid[i]->hide();
                }
            rocket->hide();
            xp=0;

            rules->show();
            rocket->show();
            start=0;

             b=4;

            if(b==4)
            emit death(score);
            score =0;
            addRect(QRectF(400,0,300,50),QPen(QColor(255, 255, 255)), QBrush(QColor(255, 255, 255)));
            QGraphicsTextItem *text = addText("Очки: " +QString::number(score));
               text->setPos(500, 0);
               text->setDefaultTextColor(QColor(0, 0, 0));
               text->setScale(2.1);
}

}
}
 }

}



Graphics::Graphics(QObject* parent):QGraphicsScene (parent)
{
    srand( time(0) );
    for(int i=0; i<20; i++){
        ux[i]= rand() % 150 + 400;
        uy[i]=rand() % 150 + 200;
        stepx[i]=rand()%8-4;
        stepy[i]=rand()%8-4;

    }
    Bullet_Init();
    Init();
    Asteroids_init();
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(Move()));
    timer->start(10);
qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    QTimer* timer2 = new QTimer(this);
    connect(timer2, SIGNAL(timeout()), this, SLOT(Asteroids()));
    timer2->start(TIMER_ASTEROID);
qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    QTimer* timer3 = new QTimer(this);
    connect(timer3, SIGNAL(timeout()), this, SLOT(Bullet_Update()));
    timer3->start(5);
}



QGraphicsItem * Graphics::itemCollidesWith(QGraphicsItem *item)
{
    QList<QGraphicsItem *> collisions = collidingItems(item);
    foreach (QGraphicsItem *it, collisions){
        if(it == item)
            continue;
        return it;
    }
    return nullptr;
}
