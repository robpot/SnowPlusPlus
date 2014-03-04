//messageBox.cpp

#include "messageBox.h"

messageBox::messageBox(QString textval, int blockId, QWidget *parent) : QWidget(parent){
   setFixedSize(196,64);
}

void messageBox::paintEvent(QPaintEvent *){
   QPainter painter(this);
   painter.drawRect(1,1 , width()-2, height()-2);
}
