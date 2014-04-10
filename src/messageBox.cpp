//messageBox.cpp

#include "messageBox.h"
#include <QDebug>
#include <QFontMetrics>

messageBox::messageBox(QString des,QWidget *parent) : QWidget(parent){
    setFixedSize(616,115);
    msg=des;
}

void messageBox::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QRect rect (0,0,width(),height());
    painter.setOpacity(0.8);
    painter.drawImage(rect, QImage(":/images/resources/messagebox.png"));
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
