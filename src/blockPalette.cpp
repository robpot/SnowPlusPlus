//blockPalette.cpp
#include "blockpalette.h"

blockPalette::blockPalette(QWidget *parent) : QWidget(parent){
   setFixedSize(205, 576);
}
void blockPalette::paintEvent(QPaintEvent *){
   QPainter painter(this);
   painter.setBrush(Qt::cyan);
   painter.drawRect(1,1,width()-2, height()-2);
}
