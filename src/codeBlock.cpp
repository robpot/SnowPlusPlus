//codeBlock.cpp

#include "codeBlock.h"
#include <QDebug>

codeBlock::codeBlock(QString textval, int blockId, QWidget *parent) : QWidget(parent){
   setFixedSize(196,64);
   text = textval;
   ID = blockId;
   numLines = text.count('\n')+1;
   active = true;
   connect(this,SIGNAL(sendUpBlock(codeBlock*)),
           parent,SIGNAL(sendUpBlock(codeBlock*)));
   
   connect(this,SIGNAL(triggerResize(int)),
	   parent,SLOT(resizeList(int)));
}
codeBlock::codeBlock(codeBlock & c, QWidget *parent) : QWidget(parent), text(c.getID()) ,palette_pos(c.getPalettePos()) ,numLines(c.getNumLines()), ID(c.getIDNum()) ,active(c.isActive())  {}


void codeBlock::deactivate()
{
   active = false;
   update();
   
}

void codeBlock::activate()
{
   
   active = true;
   update();
}

void codeBlock::paintEvent(QPaintEvent *){
   QPainter painter(this);
   QRect bound(0,0,width(),height());
   if(active)
   {
      painter.setOpacity(0.7);
      painter.drawImage(bound,QImage(":/images/resources/block.png"));
      painter.setOpacity(1.0);
      painter.drawText(bound,text,QTextOption(Qt::AlignCenter));
   }
   else
   {
      painter.setOpacity(0.7);
      QPixmap blah(":/images/resources/block.png");
      blah.setMask(blah.createMaskFromColor(Qt::gray));
      painter.drawPixmap(bound, blah);
      painter.setOpacity(1.0);
      painter.setPen(Qt::gray);
      painter.drawText(bound,text,QTextOption(Qt::AlignCenter));
   }
}

void codeBlock::mousePressEvent(QMouseEvent *event)
{
   if((active) && (event->buttons() == Qt::LeftButton))
   {
      
      emit sendUpBlock(this);
   }
}

void codeBlock::mouseReleaseEvent(QMouseEvent *event)
{
   if(event->buttons() == Qt::LeftButton){
      
      emit sendUpBlock(NULL);
   }
}

void codeBlock::mouseMoveEvent(QMouseEvent *event)
{
   if((active)&&(event->buttons() == Qt::LeftButton))
   {
      
      QDrag* drag = new QDrag(this);
      QPixmap dragpixmap(":/images/resources/block.png");
      dragpixmap = dragpixmap.scaled(width()/2,height()/2);
      drag->setPixmap(dragpixmap);
      QMimeData *mimeData = new QMimeData;
      drag->setMimeData(mimeData);
      emit triggerResize(ID);
      Qt::DropAction dropAction = drag->exec();
  }
}

