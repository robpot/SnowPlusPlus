//dropZone.cpp
#include "dropZone.h"
#include <QDebug>

dropZone::dropZone(QString s, int i ,QWidget *p) : QWidget(p){
   baseWidth = 154;
   baseHeight = 12;
   setGeometry(x(),y(),baseWidth,baseHeight);
   setAcceptDrops(true);
   text =s;
   ID = i;
}

void dropZone::setDragStorage(dragStorage *store) {
   drag = store;
}

void dropZone::paintEvent(QPaintEvent *){
   QPainter painter(this);
   QRect bound(0,0,width(),height());
   painter.setBrush(Qt::magenta);
   painter.drawRect(1,1,width()-2, height()-2);
   painter.drawText(bound, text, QTextOption(Qt::AlignCenter));
}

void dropZone::dragEnterEvent(QDragEnterEvent *event)
{
   qDebug()<<"Entered "<<text<<endl;
   qDebug()<<"drag ID: "<<drag->getCurrent()->getID();
   setGeometry(x(),y(),drag->getCurrent()->width(),drag->getCurrent()->height());
   event->acceptProposedAction();
}

void dropZone::dropEvent(QDropEvent *event)
{
  qDebug()<<"Dropped on "<<text;
}
