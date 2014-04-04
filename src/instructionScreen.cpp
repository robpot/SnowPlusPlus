#include "instructionScreen.h"
#include <QDebug>

instructionScreen::instructionScreen(QWidget *parent) :
  QGraphicsScene(parent)
{
  setSceneRect(0,0,1024,576);
  snowmantimer = new QTimer(this);
  tic = new QTimer(this);
  connect(snowmantimer,SIGNAL(timeout()),this,SLOT(moveSnowman()));
  connect(tic,SIGNAL(timeout()),this,SLOT(progress()));
  frame = new QGraphicsPixmapItem(QPixmap(":images/resources/tut1.png"));
  backdrop = new QGraphicsPixmapItem(QPixmap(":images/resources/backdrop_winter.png"));
  snowman = new QGraphicsPixmapItem(QPixmap(":/images/resources/frostyhorse.png"));
  speech1 = new QGraphicsPixmapItem(QPixmap(":/images/resources/stage1.png"));
  speech2 = new QGraphicsPixmapItem(QPixmap(":/images/resources/stage2.png"));
  speech3 = new QGraphicsPixmapItem(QPixmap(":/images/resources/stage3.png"));
  speech4 = new QGraphicsPixmapItem(QPixmap(":/images/resources/stage4.png"));
  continuewithtut = new snowButton(0,new QPixmap(":/images/resources/continuebutton1.png"), new QPixmap(":/images/resources/continuebutton2.png"));
  connect(continuewithtut,SIGNAL(clicked()),this,SLOT(progress()));
  continuewithtut->hide();
  stage = 0;

  snowmanfinalx = width()/2;
  snowmanfinaly = height()-(width()/2);
  snowmanstartx = width();
  snowmanstarty = height()-(width()/2);

  backdrop->setPos(0,0);
  frame->setPos(0,0);
  snowman->setPos(snowmanstartx,snowmanstarty);
  speech1->setPos(0,0);
  speech2->setPos(0,0);
  speech3->setPos(0,0);
  speech4->setPos(0,0);
  continuewithtut->move(2,height()-102);

  addItem(backdrop);
  addItem(snowman);

  snowmantimer->start(4);
}

void instructionScreen::moveSnowman()
{
  if(snowman->x() > snowmanfinalx)
    snowman->moveBy(-1,0);
  else
  {
    snowmantimer->stop();
    tic->start(100);
  }
}

void instructionScreen::progress()
{
  stage++;
  switch(stage)
  {
    case 0:
      break;
    case 1:
      addItem(speech1);
      tic->setInterval(2500);
      break;
    case 2:
      removeItem(speech1);
      addItem(speech2);
      tic->setInterval(1750);
      break;
    case 3:
      removeItem(speech2);
      addItem(speech3);
      tic->setInterval(2500);
      break;
    case 4:
      removeItem(speech3);
      addItem(speech4);
      break;
    case 5:
      addWidget(continuewithtut);
      continuewithtut->show();
      tic->stop();
      break;
    case 6:
      removeItem(speech4);
      removeItem(snowman);
      backdrop->setPixmap(QPixmap(":images/resources/tutbackdrop.png"));
      addItem(frame);
      break;
    case 7:
      frame->setPixmap(QPixmap(":images/resources/tut2.png"));
      break;
    case 8:
      frame->setPixmap(QPixmap(":images/resources/tut3.png"));
      break;
    case 9:
      frame->setPixmap(QPixmap(":images/resources/tut4.png"));
      break;
    case 10:
      frame->setPixmap(QPixmap(":images/resources/tut5.png"));
      break;
    case 11:
      frame->setPixmap(QPixmap(":images/resources/tut6.png"));
      break;
    case 12:
      frame->setPixmap(QPixmap(":images/resources/tut7.png"));
      break;
    case 13:
      frame->setPixmap(QPixmap(":images/resources/tut8.png"));
      break;
    case 14:
      frame->setPixmap(QPixmap(":images/resources/tut9.png"));
      break;
    case 15:
      frame->setPixmap(QPixmap(":images/resources/tut10.png"));
      break;
    case 16:
      frame->setPixmap(QPixmap(":images/resources/tut11.png"));
      break;
    default:
      break;
  }
}
