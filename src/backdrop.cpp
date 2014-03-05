//backdrop.cpp

#include "backdrop.h"

backdrop::backdrop(QWidget *parent) : QWidget(parent){
   setFixedSize(1024,576);
}

void backdrop::paintEvent(QPaintEvent *){
   QPainter painter(this);
   QRect rect(0,0,width(),height());
   painter.drawImage(rect,QImage(":/images/resources/backdrop_winter.png"));
}
