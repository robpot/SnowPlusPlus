//snowman.cpp

#include "snowman.h"

snowman::snowman(QWidget *parent) : QWidget(parent){
   setFixedSize(204,308);
}

void snowman::paintEvent(QPaintEvent *){
   QPainter painter(this);
   QRect rect(0,0,width(),height());
   painter.drawImage(rect,QImage(":/images/resources/snowman_A_0.png"));
}
