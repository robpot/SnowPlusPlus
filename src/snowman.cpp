//snowman.cpp

#include "snowman.h"

snowman::snowman(QWidget *parent) : QWidget(parent){
   setFixedSize(204,308);
}

void snowman::paintEvent(QPaintEvent *){
   QPainter painter(this);
   painter.setBrush(Qt::gray);
   painter.drawRect(1,1 , width()-2, height()-2);
}
