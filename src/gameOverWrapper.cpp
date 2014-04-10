#include "gameOverWrapper.h"

gameOverWrapper::gameOverWrapper(QWidget *parent, int base, int timerem, int snowrem, int dif)
   : QWidget(parent)
{
   screen=new gameOverScreen(this,base,timerem,snowrem,dif);
   connect(screen,SIGNAL(sendexit()),this,SIGNAL(restart()));
   view=new QGraphicsView(screen);

   QVBoxLayout *vlayout=new QVBoxLayout(this);
   vlayout->addWidget(view);

   show();
}
