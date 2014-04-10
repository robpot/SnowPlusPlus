#include "gameOverWrapper.h"

gameOverWrapper::gameOverWrapper(QWidget *parent, int base, int timerem, int snowrem, int dif)
   : QWidget(parent)
{
   setFixedSize(1024,576);
   screen=new gameOverScreen(this,base,timerem,snowrem,dif);
   connect(screen,SIGNAL(sendexit()),this,SIGNAL(restart()));
   view=new QGraphicsView(this);
   view->setScene(screen);
   view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

   show();
}
