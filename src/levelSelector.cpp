//levelselector.cpp
#include "levelSelector.h"
#include <QDebug>

levelSelector::levelSelector(QWidget *parent) : QWidget(parent){
   setFixedSize(1024, 576);
   directory = new QDir("/levels");
   QFileInfoList fileList;
   QStringList filters;
   filters<<"*.txt";
   fileList=directory->entryInfoList(filters);

   // QDebug has been put here
   for(int i=0; i<fileList.size(); i++){
      list<<fileList[i].baseName();
      qDebug() << list.last();
   }

   for(int i=0;i<list.size(); i++){
      levelList.append(new levelBlock(list[i],this));
      connect(levelList[i],SIGNAL(levelSelected(QString)),
	      this,SIGNAL(levelSelected(QString)));
   }
  
}

//CHANGE the images of case 1 and 2 to spring and summer, respectively
void levelSelector::paintEvent(QPaintEvent *) {
   QPainter painter(this);
   QRect rect(0,0,width(),height());
   switch(difficulty) {
      case 0:	 
	 painter.drawImage(rect,QImage(":/images/resources/backdrop_winter.png"));
	 break;
      case 1:
	 painter.drawImage(rect,QImage(":/images/resources/backdrop_winter.png"));
	 break;
      case 2:
	 painter.drawImage(rect,QImage(":/images/resources/backdrop_winter.png"));
	 break;
   }
   
}

void levelSelector::difficultySelected(int diff) {
   difficulty = diff;
}
