//scorebox.cpp

#include "scorebox.h"

scorebox::scorebox(QString textval, int blockId, QWidget *parent) : QWidget(parent){
   setFixedSize(204,58);
}

void scorebox::paintEvent(QPaintEvent *){
   QPainter painter(this);
   painter.drawRect(1,1 , width()-2, height()-2);
}
