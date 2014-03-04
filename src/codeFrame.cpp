//codeFrame.cpp
#include "codeFrame.h"

codeFrame::codeFrame(QWidget *parent): QWidget(parent){
   setFixedSize(154, 12);
}

void codeBlock::paintEvent(QPaintEvent *){
   QPainter painter(this);
   painter.drawRect(1,1,width()-2, height()-2);

}
