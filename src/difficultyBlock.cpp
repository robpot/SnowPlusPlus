//Erin, Jahson, Jesze, Rob, Steven
//Spring 2014 
//difficultyBlock.cpp
// 
// Paints the scenes in the difficulty choice screen.
#include "difficultyBlock.h"

difficultyBlock::difficultyBlock(QString textVal, int blockDiff, QWidget *parent) : QWidget(parent) {
   setFixedSize(700, 100);
   text = textVal;
   difficulty = blockDiff;
}

//Height in bound might do something weird?
void difficultyBlock::paintEvent(QPaintEvent *) {
   QPainter painter(this);
   QRect boundOne(20,16,547,height()-30);
   QRect boundTwo(543,5,153,height()-10);
   QRect boundary(0, 0, width(), height());
   QImage *backImage;
   backImage = new QImage(":/images/resources/block.png");
   painter.drawImage(boundary, *backImage);
   //Change this image later please.
   QImage *image;
   QImage *fontImage;
   switch(difficulty) {
      case 0:
	 image = new QImage(":/images/resources/backdrop_winter.png");
	 fontImage = new QImage(":/images/resources/winter.png");
	 break;
      case 1:
	 image = new QImage(":/images/resources/backdrop_spring.png");
	 fontImage = new QImage(":/images/resources/spring.png");
	 break;
      case 2:
	 image = new QImage(":/images/resources/backdrop_summer.png");
	 fontImage = new QImage(":/images/resources/summer.png");
	 break;
   }
   painter.drawImage(boundOne, *fontImage);
   painter.drawImage(boundTwo, *image);
}

void difficultyBlock::mousePressEvent(QMouseEvent *event) {
//   if(event->buttons() == Qt::LeftButton)
      emit difficultySelected(difficulty);

}
