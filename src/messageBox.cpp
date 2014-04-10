//messageBox.cpp

#include "messageBox.h"
#include <QFontMetrics>

messageBox::messageBox(QString des,QWidget *parent) : QWidget(parent){
    setFixedSize(616,115);
    msg=des;
}

void messageBox::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QRect rect (0,0,width(),height());
    QRect textrect (4,4,width()-10,height()-10);
    painter.setOpacity(0.8);
    painter.drawImage(rect, QImage(":/images/resources/messagebox.png"));
    QPainter text(this);
    text.drawText(textrect,Qt::AlignCenter,msg);
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
