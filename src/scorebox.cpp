//Erin, Jahson, Jesze, Steven
//Spring 2014
//scorebox.cpp

#include "scorebox.h"

//Creates timers and a layout which holds the countdown timer and the score 
scorebox::scorebox(QWidget *parent, int min, int sec) : QWidget(parent){
    setFixedSize(204,58);
    QGridLayout *layout=new QGridLayout();
    QLabel *score=new QLabel("???");
    timeElapsed=new QTimer();
    timeElapsed->setInterval(min*60000+sec*1000);
    lcdTimer=new LCDTimer(this,min,sec);
    layout->addWidget(score,0,0);
    layout->addWidget(lcdTimer,0,1);
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
