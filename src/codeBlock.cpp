//Erin, Jahson, Jesze, Rob, Steven
//Spring 2014
//codeBlock.cpp

#include "codeBlock.h"
#include <QDebug>
// Constructor that creates the codeblock, with each code block
// having the blockId and the text within the block.
// Connects to relevent parents upon signals
codeBlock::codeBlock(QString textval, int blockId, QWidget *parent) : QWidget(parent){
   setFixedSize(196,64);
   text = textval;
   ID = blockId;
   numLines = text.count('\n')+1;
   active = true;
   connect(this,SIGNAL(sendUpBlock(codeBlock*)),
           parent,SIGNAL(sendUpBlock(codeBlock*)));
   // removeFromList does not exist anymore DO SOMETHING
   //connect(this,SIGNAL(sendUpBlock(codeBlock*)),
   //        parent,SLOT(removeFromList(codeBlock*)));
   connect(this,SIGNAL(triggerResize(int)),
	   parent,SLOT(resizeList(int)));
}
// greys outs codeBlocks after they are moved to codeFrame
void codeBlock::deactivate()
{
   active = false;
   update();
}
//toggles from grey back to normal when beign drawn in codeFrame
void codeBlock::activate()
{
   active = true;
   update();
}
// Paints the blocks to be into the code palette
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
//sends block to drag storage for temporary storage until drop
void codeBlock::mousePressEvent(QMouseEvent *event)
{
   if((active) && (event->buttons() == Qt::LeftButton))
   {
      emit sendUpBlock(this);

   }
}
// removes the block from dragStorage after mouse is released
void codeBlock::mouseReleaseEvent(QMouseEvent *event)
{
  if(event->buttons() == Qt::LeftButton)
    emit sendUpBlock(NULL);
}
// Redraws the block as the mouse is moved while being dragged
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
      //emit triggerResize(ID);
  }
}

