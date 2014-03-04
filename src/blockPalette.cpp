//blockPalette.cpp
#include "blockpalette.h"

blockplatte::blockPalette(QWidget *parent){
   setFixedSize(205, 576);
}
void blockPalette::paintEvent(QPaintEvent *){
   QPainter painter(this);
   painter.drawRect(1,1,width()-2, height()-2);
}
