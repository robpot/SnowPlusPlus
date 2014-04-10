// Erin, Jahson, Jesze, Rob, Steven
// Spring 2014
// This displays the game over screen with the score , time remaining,
// and snowflakes remaining.
#include "gameOverScreen.h"
#include <QDebug>
gameOverScreen::gameOverScreen(QWidget *parent, int base, int timerem, int snowrem, int dif)
  : QGraphicsScene(parent)
{
  setSceneRect(0,0,1024,576);
  int scorespacing = 16;
  int scorefontsize = 16;
  QFont font("Times",scorefontsize);
  setFont(font);
  score.append("Total Score: ");
  totalscore = base+((timerem/1000)*(dif+1))-100*(10-snowrem);
  score.append(QString::number(totalscore));
  basescore.append("Base Score: ");
  basescore.append(QString::number(base));
  timeremaining.append("Time Left: ");
  timeremaining.append(QString::number(timerem/1000));
  timeremaining.append(" sec");
  snowflakeamount.append("Snowflakes Remaining: ");
  snowflakeamount.append(QString::number(snowrem));

  step1done = false;
  step2done = false;
  step3done = false;

  tic = new QTimer(this);
  connect(tic,SIGNAL(timeout()),this,SLOT(animate()));

  tic->start(4);

  snowman = new QGraphicsPixmapItem();
  snowman->setPixmap(QPixmap(":/images/resources/frostyhorse.png"));
  backdrop = new QGraphicsPixmapItem();
  backdrop->setPixmap(QPixmap(":/images/resources/backdrop_winter.png"));
  scorebanner = new QGraphicsPixmapItem();
  scorebanner->setPixmap(QPixmap(":/images/resources/scorebanner.png"));
  goodjobbubble = new QGraphicsPixmapItem();
  goodjobbubble->setPixmap(QPixmap(":/images/resources/goodjobbubble.png"));


  backdrop->setPos(0,0);
  addItem(backdrop);

  QGraphicsPixmapItem* whiteback = new QGraphicsPixmapItem();
  whiteback->setPixmap(QPixmap(":/images/resources/dropspace.png"));
  whiteback->setPos(0,0);
  whiteback->setOpacity(0.8);
  addItem(whiteback);

  snowmanfinalx = width()/2;
  snowmanfinaly = height()-(width()/2);
  snowmanstartx = width();
  snowmanstarty = height()-(width()/2);
  snowman->setPos(snowmanstartx,snowmanstarty);
  addItem(snowman);

  scorefinalx = 31;
  scorefinaly = 31;
  scorestartx = 31;
  scorestarty = -scorebanner->pixmap().height();
  qDebug()<<scorestarty;

  scorebanner->setPos(scorestartx,scorestarty);
  addItem(scorebanner);


  basescorerect = new QGraphicsTextItem(basescore);
  basescorerect->setPos(31,120+scorefontsize+scorespacing);
  timeremainingrect = new QGraphicsTextItem(timeremaining);
  timeremainingrect->setPos(31,144+scorefontsize+scorespacing);
  snowflakeamountrect = new QGraphicsTextItem(snowflakeamount);
  snowflakeamountrect->setPos(31,168+scorefontsize+scorespacing);
  scorerect = new QGraphicsTextItem(score);
  scorerect->setPos(64,192+scorefontsize+scorespacing);
  scorerect = new QGraphicsTextItem(score);
  scorerect->setPos(64,192+scorefontsize+scorespacing);

  goodjobmessage.append("That solution sure was cool, boy howdy!");

}

void gameOverScreen::paintEvent(QPaintEvent *)
{
}

void gameOverScreen::closeAndSaveScore()
{
  emit sendexit();
}

void gameOverScreen::animate()
{
  if(!step1done)
  {
    if(snowman->x() > snowmanfinalx)
      snowman->moveBy(-1,0);
    else
    {
        goodjobbubble->setPos((width()/2)+128,0);
        addItem(goodjobbubble);
        QGraphicsTextItem* text = new QGraphicsTextItem(goodjobmessage);
        text->setTextWidth(116);
        text->setFont(QFont("Times",12));
        text->setPos((width()/2)+128+16,24);
        addItem(text);
        step1done = true;
    }
  }
  if(!step2done)
  {
    if(scorebanner->y() < scorefinaly)
      scorebanner->moveBy(0,1);
    else
    {
        basescorerect->setFont(QFont("Times",16));
        timeremainingrect->setFont(QFont("Times",16));
        snowflakeamountrect->setFont(QFont("Times",16));
        scorerect->setFont(QFont("Times",24));
        if(basescorerect->scene() == 0)
          addItem(basescorerect);
        else if(timeremainingrect->scene() == 0)
          addItem(timeremainingrect);
        else if(snowflakeamountrect->scene() == 0)
          addItem(snowflakeamountrect);
        else
          step2done = true;
    }
  }
  if(step1done && step2done && !step3done)
  {
    if(scorerect->scene() == 0)
      addItem(scorerect);
    exitscreen = new QPushButton("Continue");
    exitscreen->setFixedSize(128,64);
    exitscreen->move(512-exitscreen->width(),height()-exitscreen->height()-32);
    addWidget(exitscreen);
    connect(exitscreen,SIGNAL(clicked()),this,SLOT(closeAndSaveScore()));
    step3done = true;
  }
}
