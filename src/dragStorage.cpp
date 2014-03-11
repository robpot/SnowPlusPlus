#include "dragStorage.h"
#include <QDebug>

dragStorage::dragStorage(QWidget *parent) :
  QWidget(parent)
{
  setFixedSize(196,64);
  current = NULL;
}

bool dragStorage::setBlock(codeBlock *block)
{
  if(block != NULL)
  {
    current = block;
    move(mapFromGlobal(QCursor::pos()));
    update();
    qDebug()<<current->getID();
    return 1;
  }
  else
    return 0;

}

void dragStorage::paintEvent(QPaintEvent *)
{
//  if(current != NULL)
//  {
//    QPainter painter(this);
//    QRect bound(0,0,width(),height());
//    painter.setOpacity(0.7);
//    painter.drawImage(bound,QImage(":/images/resources/block.png"));
//    painter.setOpacity(1.0);
//    //painter.drawText(bound,text,QTextOption(Qt::AlignCenter));
//  }
}

void dragStorage::mouseMoveEvent(QMouseEvent *event)
{
 // move(QCursor::pos());
}
