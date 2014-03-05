//codeFrame.cpp
#include "codeFrame.h"

codeFrame::codeFrame(QWidget *parent): QWidget(parent){
   setFixedSize(616, 461);
}

void codeFrame::paintEvent(QPaintEvent *){
   QPainter painter(this);
   painter.setBrush(Qt::red);
   painter.drawRect(1,1,width()-2, height()-2);

}
