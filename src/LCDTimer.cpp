#include "LCDTimer.h"

LCDTimer::LCDTimer(QWidget * parentWidget,int minutes,int seconds){
    timer = new QTimer();
    timer->setInterval(1000);
    timeValue = new QTime(0,minutes,seconds);
    this->setParent(parentWidget);
    this->display(timeValue->toString());
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(setDisplay()));
}
void LCDTimer::setDisplay(){
    timeValue->setHMS(0,this->timeValue->addSecs(-1).minute(),this->timeValue->addSecs(-1).second());
    display(this->timeValue->toString());
}
