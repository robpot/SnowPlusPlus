//scorebox.cpp

#include "scorebox.h"

scorebox::scorebox(QWidget *parent, int min, int sec) : QWidget(parent){
    setFixedSize(204,58);
    QGridLayout *layout=new QGridLayout();
    QLabel *score=new QLabel("???");
    timer=new LCDTimer(this,min,sec);
    layout->addWidget(score,0,0);
    layout->addWidget(timer,0,1);
    setLayout(layout);
    timer->timer->start();
}

void scorebox::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.setPen(QPen(QBrush(Qt::black),3));
    painter.drawRect(1,1 , width()-2, height()-2);
}
