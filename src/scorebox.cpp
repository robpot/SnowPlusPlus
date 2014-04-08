//Erin, Jahson, Jesze, Steven
//Spring 2014
//scorebox.cpp

#include "scorebox.h"

//Creates timers and a layout which holds the countdown timer and the score 
scorebox::scorebox(QWidget *parent, int min, int sec) : QWidget(parent){
    setFixedSize(204,116);
    QGridLayout *layout=new QGridLayout();
    flakeCount=10;
    flakes=new SnowFlakes(flakeCount,this);
    timeElapsed=new QTimer();
    timeElapsed->setInterval(min*60000+sec*1000);
    lcdTimer=new LCDTimer(this,min,sec);
    
    layout->addWidget(lcdTimer,0,0,1,1);
    layout->addWidget(flakes,1,0,2,1);
    setLayout(layout);
    lcdTimer->ticks->start();
    timeElapsed->start();
    connect(timeElapsed,SIGNAL(timeout()),lcdTimer->ticks,SLOT(stop()));
    connect(timeElapsed,SIGNAL(timeout()),this,SIGNAL(gameOver()));
}

//Updates the clock
void scorebox::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.setPen(QPen(QBrush(Qt::black),3));
    painter.drawRect(1,1 , width()-2, height()-2);
}
void scorebox::snowmanClicked() {
   flakeCount--;
   flakes->loseFlake(flakeCount);
   if(flakeCount == 0)
   {
      emit gameOver();
   }
}
