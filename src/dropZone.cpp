//dropZone.cpp
#include "dropZone.h"
#include <QDebug>

dropZone::dropZone(QString s, int i ,QWidget *p) : QWidget(p)
{
   baseWidth = 154;
   baseHeight = 12;
   setGeometry(x(),y(),baseWidth,baseHeight);
   emit newSize();
   setAcceptDrops(true);
   text =s;
   ID = i;
   block = NULL;
}

void dropZone::setDragStorage(dragStorage *store)
{
   drag = store;
}

void dropZone::paintEvent(QPaintEvent *)
{
   QPainter painter(this);
   QRect bound(0,0,width(),height());
   painter.setPen(Qt::DashDotLine);
   painter.drawRect(1,1,width()-2, height()-2);
   painter.drawText(bound, text, QTextOption(Qt::AlignCenter));
}

void dropZone::dragEnterEvent(QDragEnterEvent *event)
{
   qDebug()<<"Entered "<<text<<endl;
   qDebug()<<"drag ID: "<<drag->getCurrent()->getID();
   setGeometry(x(),y(),drag->getCurrent()->width(),drag->getCurrent()->height());
   emit newSize();
   event->acceptProposedAction();
}

void dropZone::dragLeaveEvent(QDragLeaveEvent *event)
{
   qDebug()<<"Leaved "<<text;
   setGeometry(x(),y(),baseWidth,baseHeight);
   emit newSize();
}

void dropZone::dropEvent(QDropEvent *event)
{
   qDebug()<<"Dropped on "<<text;
   setGeometry(x(),y(),432,12*drag->getCurrent()->getNumLines()+5*drag->getCurrent()->getNumLines());
   emit newSize();
   block = drag->getCurrent();
   text = block->getID();
   update();
}

void dropZone::mousePressEvent(QMouseEvent *event)
{
   if(event->buttons() == Qt::LeftButton)
      drag->setBlock(block);
}

void dropZone::mouseReleaseEvent(QMouseEvent *event)
{
   if(event->buttons() == Qt::LeftButton)
      drag->setBlock(NULL);
}

void dropZone::mouseMoveEvent(QMouseEvent *event)
{
  if(event->buttons() == Qt::LeftButton)
  {
      QDrag* drag = new QDrag(this);
      QPixmap dragpixmap(":/images/resources/block.png");
      dragpixmap = dragpixmap.scaled(width()/2,height()/2);
      drag->setPixmap(dragpixmap);
      QMimeData *mimeData = new QMimeData;
      drag->setMimeData(mimeData);
      Qt::DropAction dropAction = drag->exec();
  }
}
