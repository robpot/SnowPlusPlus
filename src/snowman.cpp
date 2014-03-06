//snowman.cpp

#include "snowman.h"

snowman::snowman(QWidget *parent) : QWidget(parent){
    setFixedSize(204,308);
    strs=new QStringList();
    strs->append(":/images/resources/snowman_A_0.png");
    strs->append(":/images/resources/snowman_B_0.png");
    strs->append(":/images/resources/snowman_C_0.png");
    strs->append(":/images/resources/snowman_D_0.png");
    count=0;
    image=new QImage();
    image->load(strs->at(count));

    timer=new QTimer(this);
    timer->setInterval(3000);
    connect(timer,SIGNAL(timeout()),this,SLOT(nextSnowman()));
    timer->start();
    if(count>3) {return;}
}


void snowman::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QRect rect(0,0,width(),height());
    painter.drawImage(rect,*image);
}
void snowman::nextSnowman(){
    if (count<3){count++;}
    image->load(strs->at(count));

    repaint();
    timer->start();
}
