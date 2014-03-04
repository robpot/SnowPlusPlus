//animation.cpp
#include "animationFrame.h"

animationFrame::animationFrame(QWidget *p) : QWidget(p){
   setFixedSize(1024,576);
}

void animationFrame::paintEvent(QPaintEvent *){
   QPainter paint(this);
   paint.drawRect(1,1,width()-2,height()-2);
}
