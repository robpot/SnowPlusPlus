//dropZone.cpp
#include "dropZone.h"

dropZone::dropZone(QString s, int i ,QWidget *p) : QWidget(p){
   setBaseSize(154,12);
   text =s;
   ID = i;
}

void dropZone::paintEvent(QPaintEvent *){
   QPainter painter(this);
   QRect bound(0,0,width(),height());
   painter.setBrush(Qt::magenta);
   painter.drawRect(1,1,width()-2, height()-2);
   painter.drawText(bound, text, QTextOption(Qt::AlignCenter));
}
