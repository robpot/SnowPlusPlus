//scorebox.cpp

#include "scorebox.h"

scorebox::scorebox(QWidget *parent) : QWidget(parent){
   setFixedSize(204,58);
}

void scorebox::paintEvent(QPaintEvent *){
   QPainter painter(this);
   painter.setBrush(Qt::green);
   painter.drawRect(1,1 , width()-2, height()-2);
}
