//dropZone.cpp
#include "dropZone.h"

dropZone::dropZone(QWidget *p) : QWidget(p){
   setBaseSize(154,12);
}

void dropZone::paintEvent(QPaintEvent *){
   QPainter painter(this);
   painter.setBrush(Qt::magenta);
   painter.drawRect(1,1,width()-2, height()-2);
}
