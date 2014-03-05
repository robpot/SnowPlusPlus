//blockPalette.cpp
#include "blockpalette.h"

blockPalette::blockPalette(QWidget *parent) : QWidget(parent){
   setFixedSize(205, 576);
}
void blockPalette::paintEvent(QPaintEvent *){
   QPainter painter(this);
   QRect rect(0,0,width(),height());
   painter.setOpacity(0.8);
   painter.drawImage(rect,QImage(":/images/resources/blockpalette.png"));
}
