//messageBox.cpp

#include "messageBox.h"

messageBox::messageBox(QWidget *parent) : QWidget(parent){
   setFixedSize(616,115);
}

void messageBox::paintEvent(QPaintEvent *){
   QPainter painter(this);
   painter.setPen(QPen(QBrush(Qt::black),3));
   painter.drawRect(1,1 , width()-2, height()-2);
}
