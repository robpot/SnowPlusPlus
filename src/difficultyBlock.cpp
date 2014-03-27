#include "difficultyBlock.h"

difficultyBlock::difficultyBlock(QString textVal, int blockDiff, QWidget *parent) : QWidget(parent) {
   setFixedSize(700, 153);
   text = textVal;
   difficulty = blockDiff;
}

//Height in bound might do something weird?
void difficultyBlock::paintEvent(QPaintEvent *) {
   QPainter painter(this);
   QRect boundOne(0,0,547,height());
   QRect boundTwo(547,0,153,height());
   painter.drawText(boudnOne, text, QTextOption(Qt::AlignLeft));
   //Change this image later please.
   QImage *image;
   switch(blockDiff) {
      case: 0
	 image = new QImage(":/images/resources/block.png");
	 break;
      case: 1
	 image = new QImage(":/images/resources/block.png");
	 break;
      case: 2
	 image = new QImage(":/images/resources/block.png");
	 break;
   }
   painter.drawImage(boundTwo, image);
}

void difficultyBlock::mousePressEvent(QMouseEvent *event) {
   if(event->buttons() == Qt::LeftButton)
      emit difficultySelected(blockDiff);
}
