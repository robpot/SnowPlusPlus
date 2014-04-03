//Erin, Jahson, Jesze, Steven
//Spring 2014
//snowman.cpp

#include "snowman.h"

//constructor loads images and timers. 
snowman::snowman(QWidget *parent, int minutes, int seconds) : QWidget(parent){
    setFixedSize(204,308);
    strs=new QStringList();
    strs->append(":/images/resources/snowman_A_0.png");
    strs->append(":/images/resources/snowman_B_0.png");
    strs->append(":/images/resources/snowman_C_0.png");
    strs->append(":/images/resources/snowman_D_0.png");

    count=0;
    image=new QImage();
    image->load(strs->at(count));
    time=new QTime(0,minutes,seconds);
    timer=new QTimer(this);
    timer->setInterval((time->minute()*60000+time->second()*1000)/4);
    connect(timer,SIGNAL(timeout()),this,SLOT(nextSnowman()));
    connect(timer,SIGNAL(timeout()),this,SLOT(sendMessage()));
    timer->start();
    if(count>3) {return;}

}

//redraws the snowman
void snowman::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QRect rect(0,0,width(),height());
    painter.drawImage(rect,*image);
}
//calles the redraw to paint the next snowman image
void snowman::nextSnowman(){
    if (count<3){count++;}
    image->load(strs->at(count));

    repaint();
    timer->start();
}

//snowman emits a string which contains a message
void snowman::sendMessage(const QString &str){
    emitMessage(str);
}

//messages sent for each time segment.
void snowman::sendMessage(){
    QString str;
    if (count<3){
    if (count==1){str="Who turned up the heat?";}
    if (count==2){str="I'm meellllttttiiinnnggg...";}
    if (count==3){str="FAIL";}
    emitMessage(str);}
}

//mesages sent for helpful hints
//Also checks the emits a signal to check correctness
void snowman::mousePressEvent(QMouseEvent *e){
    sendMessage("testtesttesttesttest \n testtesttesttesttesttest. ");

}
