//codeBlock.cpp

#include "codeBlock.h"
#include <QDebug>

codeBlock::codeBlock(QString textval, int blockId, QWidget *parent) : QWidget(parent){
   setFixedSize(196,64);
   text = textval;
   connect(this,SIGNAL(sendUpBlock(codeBlock*)),
           parent,SIGNAL(sendUpBlock(codeBlock*)));
   connect(this,SIGNAL(sendUpBlock(codeBlock*)),
           parent,SLOT(removeFromList(codeBlock*)));
}

void codeBlock::paintEvent(QPaintEvent *){
   QPainter painter(this);
   QRect bound(0,0,width(),height());
   painter.setOpacity(0.7);
   painter.drawImage(bound,QImage(":/images/resources/block.png"));
   painter.setOpacity(1.0);
   painter.drawText(bound,text,QTextOption(Qt::AlignCenter));
}

void codeBlock::mousePressEvent(QMouseEvent *event)
{
  if(event->buttons() == Qt::LeftButton)
    emit sendUpBlock(this);
}

void codeBlock::mouseReleaseEvent(QMouseEvent *event)
{
  if(event->buttons() == Qt::LeftButton)
    emit sendUpBlock(NULL);
}

void codeBlock::mouseMoveEvent(QMouseEvent *event)
{
  if(event->buttons() == Qt::LeftButton)
  {
      QDrag* drag = new QDrag(this);
      drag->setPixmap(QPixmap(":/images/resources/block.png"));
      QMimeData *mimeData = new QMimeData;
      drag->setMimeData(mimeData);
      Qt::DropAction dropAction = drag->exec();
  }
}

