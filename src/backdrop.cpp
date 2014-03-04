//backdrop.cpp

#include "backdrop.h"

backdrop::backdrop(QWidget *parent) : QWidget(parent){
   setFixedSize(1024,576);
}

void backdrop::paintEvent(QPaintEvent *){
   QPainter painter(this);
   painter.drawRect(1,1 , width()-2, height()-2);
}
