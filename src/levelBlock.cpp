//Erin, Jahson, Jesze, Rob, Steven
//Spring 2014
// This creates the block that shows the name of the level.
#include "levelBlock.h"
#include <QFont>

levelBlock::levelBlock(QString textVal, QWidget *parent) : QWidget(parent) {
   levelName = textVal;
}

void levelBlock::paintEvent(QPaintEvent *) {
   QPainter painter(this);
   QRect rect(0,0,width(),height());
   painter.drawImage(rect, QImage(":/images/resources/block.png"));
   if(levelName.size() >=15){
      painter.setFont(QFont("Times", 16));}
   if(levelName.size() > 9 && levelName.size() < 15){
      painter.setFont(QFont("Times", 30));}
   if(levelName.size() <= 9){
      painter.setFont(QFont("Times", 36));}
   painter.drawText(rect,Qt::AlignCenter,levelName);
}

void levelBlock::mousePressEvent(QMouseEvent* event) {
   if((levelName != "") && (event->buttons() == Qt::LeftButton))
      emit levelSelected(levelName);
}

void levelBlock::changeText(QString s) {
   levelName = s;
   update();
}
