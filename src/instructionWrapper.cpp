#include "instructionWrapper.h"

instructionWrapper::instructionWrapper(QWidget *parent)
   : QWidget(parent)
{
   screen=new instructionScreen(this);
   connect(screen,SIGNAL(close()),this,SIGNAL(close()));
   view=new QGraphicsView(screen);

   QVBoxLayout *vlayout=new QVBoxLayout(this);
   vlayout->addWidget(view);

   show();
}
