//codeBlock.cpp

#include "snowPlusPlus.h"

snowPlusPlus::snowPlusPlus(QWidget *parent) : QWidget(parent){
   setFixedSize(1024,576);
}

void snowPlusPlus::paintEvent(QPaintEvent *){
   QPainter painter(this);
   painter.drawRect(1,1 , width()-2, height()-2);
}
