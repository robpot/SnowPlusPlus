//snowman.cpp

#include "snowman.h"

snowman::snowman(QString textval, int blockId, QWidget *parent) : QWidget(parent){
   setFixedSize(204,308);
}

void snowman::paintEvent(QPaintEvent *){
   QPainter painter(this);
   painter.drawRect(1,1 , width()-2, height()-2);
}
