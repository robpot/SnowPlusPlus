//messageBox.cpp

#include "messageBox.h"
#include <QDebug>
#include <QFontMetrics>

messageBox::messageBox(QWidget *parent) : QWidget(parent){
    setFixedSize(616,115);
    msg="";
}

void messageBox::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QRect rect (0,0,width(),height());
    painter.setOpacity(0.8);
    painter.drawImage(rect, QImage(":/images/resources/messagebox.png"));
    //painter.setPen(QPen(QBrush(Qt::black),3));
    //painter.drawRect(1,1 , width()-2, height()-2);
    QPainter text(this);
    text.drawText(rect,Qt::AlignCenter,msg);
}
void messageBox::catchMessage(const QString &str){

    msg=str;
    update();
}

void messageBox::gameEnd()
{
   msg = "Game Over.";
   update();
}
