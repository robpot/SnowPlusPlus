//backdrop.cpp
//Erin, Jahson, Jesze, Rob, Steven
//Spring 2014

#include "backdrop.h"

backdrop::backdrop(int diff,QWidget *parent) : QWidget(parent){
   setFixedSize(1024,576);
   d=diff;
}

//paints the background into the backdrop frame
void backdrop::paintEvent(QPaintEvent *){
   QPainter painter(this);
   QRect rect(0,0,width(),height());
   switch(d){
      case 0:
	 painter.drawImage(rect,QImage(":/images/resources/backdrop_winter.png"));
	 break;
      case 1:
	 painter.drawImage(rect,QImage(":/images/resources/backdrop_spring.png"));
	 break;
      case 2:
	 painter.drawImage(rect,QImage(":/images/resources/backdrop_summer.png"));
	 break;
      default:
	 painter.drawImage(rect,QImage(":/images/resources/backdrop_winter.png"));
	 break;
   }
}
