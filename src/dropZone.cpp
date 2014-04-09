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
   oldtext = text;
   ID = i;
   pen.setStyle(Qt::DashDotLine);
   pen.setColor(Qt::black) ;
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
   painter.setPen(pen);
   painter.drawRect(1,1,width()-2, height()-2);
   painter.drawText(bound, text, QTextOption(Qt::AlignLeft));
}

void dropZone::dragEnterEvent(QDragEnterEvent *event)
{
  
   if(block == NULL)
   {
      setGeometry(x(),y(),drag->getCurrent()->width(),drag->getCurrent()->height());
  
      emit newSize();
  
   }
   event->acceptProposedAction();
}

void dropZone::dragLeaveEvent(QDragLeaveEvent *event)
{
   if(block == NULL)
   {
      setGeometry(x(),y(),baseWidth,baseHeight);
      emit newSize();
   }
}

void dropZone::dropEvent(QDropEvent *event)
{
   //qDebug() << "Drag into Drop";
   setGeometry(x(),y(),432,12*drag->getCurrent()->getNumLines()+5*drag->getCurrent()->getNumLines());
   emit newSize();
   if(block != NULL)
    block->activate();
   else
    oldtext = text;
   block = drag->getCurrent();
   text = block->getID();
   update();
}

void dropZone::mousePressEvent(QMouseEvent *event)
{
   //qDebug() << "zone mousePress";
   if(event->buttons() == Qt::LeftButton)
      drag->setBlock(block);
}

void dropZone::mouseReleaseEvent(QMouseEvent *event)
{
   //qDebug() << "release event";
   if(event->buttons() == Qt::LeftButton)
      drag->setBlock(NULL);
}

void dropZone::mouseMoveEvent(QMouseEvent *event)
{
  if(block != NULL && event->buttons() == Qt::LeftButton)
  { 
     QDrag* dragger = new QDrag(this);   
     QPixmap dragpixmap(":/images/resources/block.png");   
     dragpixmap = dragpixmap.scaled(drag->getCurrent()->width()/2,drag->getCurrent()->height()/2);
     dragger->setPixmap(dragpixmap);   
     QMimeData *mimeData = new QMimeData;
     text = oldtext;
     dragger->setMimeData(mimeData);
     Qt::DropAction dropAction = dragger->exec();
     block = NULL;
     setGeometry(x(),y(),baseWidth,baseHeight);
     emit newSize();
     update();
  }
}

bool dropZone::correctness(){
   if(block == NULL){
      return false;
   }else{
      qDebug() <<text << "My ID ?= Held ID" << block->getRealID();
      if(block->getRealID() == ID){
	 return true;
      }else{
	 return false;
      }
   }
}

void dropZone::setPen(QPen aPen){
   pen = aPen;
}
