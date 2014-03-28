#include "gameOverScreen.h"

gameOverScreen::gameOverScreen(QWidget *parent, int base, int timerem, int snowrem) :QWidget(parent)
{
  setFixedSize(1024,576);
  int scorespacing = 16;
  int scorefontsize = 16;
  QFont font("Times",scorefontsize);
  setFont(font);
  score.append("Total Score: ");
  //Add score via formula
  basescore.append("Base Score: ");
  basescore.append(QString::number(base));
  timeremaining.append("Time Bonus: ");
  timeremaining.append(QString::number(timerem));
  snowflakeamount.append("Snowflakes Remaining: ");
  snowflakeamount.append(QString::number(snowrem));

  scoreintimer = new QTimer(this);
  movebaserect = new QTimer(this);
  movetimerect = new QTimer(this);
  movesnowflakerect = new QTimer(this);
  movesnowman = new QTimer(this);

  snowman.load(":/images/resources/frostyhorse.png");
  backdrop.load(":/images/resources/backdrop_winter.png");
  snowflake.load(":/images/resources/snowflake.png");
  scorebanner.load(":/images/resources/scorebanner.png");
  goodjobbubble.load(":/images/resources/goodjobbubble.png");

  snowmanrect = new QRect(width()/2,576-512,512,512);
  snowflakerect = new QRect(0,0,32,32);
  scorebannerrect = new QRect(31,31,450,64);
  backdroprect = new QRect(0,0,width(),height());
  speechrect = new QRect((width()/2)+128,0,128,128);
  speechtextrect = new QRect((width()/2)+128,6,116,116);
  basescorerect = new QRect(31,120+scorefontsize+scorespacing,256,24);
  timeremainingrect = new QRect(31,144+scorefontsize+scorespacing,256,24);
  snowflakeamountrect = new QRect(31,168+scorefontsize+scorespacing,256,24);
  scorerect = new QRect(64,192+scorefontsize+scorespacing,256,32);

  goodjobmessage.append("That solution sure was cool, boy howdy!");

  exitscreen = new QPushButton("Continue",this);
  exitscreen->setFixedSize(128,64);
  exitscreen->move(512-exitscreen->width(),height()-exitscreen->height()-32);
  connect(exitscreen,SIGNAL(clicked()),this,SLOT(closeAndSaveScore()));
}

void gameOverScreen::paintEvent(QPaintEvent *)
{
  QPainter painter(this);
  painter.drawImage(*backdroprect,backdrop);
  QRect whiteback(0,0,width()/2,height()/2);
  painter.setOpacity(0.8);
  painter.drawImage(whiteback,QImage(":/images/resources/dropspace.png"));
  painter.setOpacity(1.0);

  QFont font("Times",12);
  painter.setFont(font);
  painter.drawImage(*speechrect,goodjobbubble);
  painter.drawText(*speechtextrect,goodjobmessage,QTextOption(Qt::AlignCenter));

  QFont font2("Times",16);
  painter.setFont(font2);
  painter.drawImage(*snowmanrect,snowman);
  painter.drawImage(*scorebannerrect,scorebanner);
  painter.drawImage(*snowflakerect,snowflake);
  painter.drawText(*scorerect,score);
  painter.drawText(*basescorerect,basescore);
  painter.drawText(*timeremainingrect,timeremaining);
  painter.drawText(*snowflakeamountrect,snowflakeamount);
}

void gameOverScreen::closeAndSaveScore()
{
  close();
}
