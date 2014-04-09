//Erin, Jahson, Jesze, Rob, Steven
//Spring 2014
//LCDTimer.cpp
// This is the timer used for the game timer
#include "LCDTimer.h"

LCDTimer::LCDTimer(QWidget * parentWidget,int minutes,int seconds){
    ticks = new QTimer();
    ticks->setInterval(1000);
    
    timeValue = new QTime(0,minutes,seconds);
    this->setParent(parentWidget);
    this->display(timeValue->toString());
    connect(ticks,SIGNAL(timeout()),this,SLOT(setDisplay()));
    connect(ticks,SIGNAL(timeout()),this,SLOT(tick()));
}
void LCDTimer::setDisplay(){
    timeValue->setHMS(0,this->timeValue->addSecs(-1).minute(),this->timeValue->addSecs(-1).second());

    display(this->timeValue->toString());
}
void LCDTimer::tick(){
   timePassed+=ticks->interval()/1000;
}
