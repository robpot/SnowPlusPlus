#include "instructionWrapper.h"
#include <QRect>
instructionWrapper::instructionWrapper(QWidget *parent)
   : QWidget(parent)
{
   setFixedSize(1024,576);
   screen=new instructionScreen(this);
   connect(screen,SIGNAL(close()),this,SIGNAL(close()));
   view=new QGraphicsView(this);
   view->setScene(screen);
   view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

   show();
}
