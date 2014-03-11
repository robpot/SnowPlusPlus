//codeBlock.cpp

#include "codeBlock.h"

codeBlock::codeBlock(QString textval, int blockId, QWidget *parent) : QWidget(parent){
   setFixedSize(196,64);
   text = textval;
}

void codeBlock::paintEvent(QPaintEvent *){
   QPainter painter(this);
   QRect bound(0,0,width(),height());
   painter.setOpacity(0.7);
   painter.drawImage(bound,QImage(":/images/resources/block.png"));
   painter.setOpacity(1.0);
   painter.drawText(bound,text,QTextOption(Qt::AlignCenter));
}
