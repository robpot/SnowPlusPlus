//codeBlock.cpp

#include "codeBlock.h"

codeBlock::codeBlock(QString textval, int blockId, QWidget *parent) : QWidget(parent){
   setBaseSize(196,64);
}

void codeBlock::paintEvent(QPaintEvent *){
   QPainter painter(this);
   painter.setBrush(Qt::white);
   painter.drawRect(1,1 , width()-2, height()-2);
}
