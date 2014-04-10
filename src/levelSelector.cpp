//levelselector.cpp
#include "levelSelector.h"
#include <math.h>

levelSelector::levelSelector(QWidget *parent) : QWidget(parent){
   setFixedSize(1024, 576);
   bacButton = new QPushButton("<-- Back",this);
   connect(bacButton, SIGNAL(clicked()), this, SIGNAL(backButton()));
   directory = new QDir("/levels");
   layout = new QGridLayout();
   for(int i = 0; i < 12; i++){
      levelList.append(new levelBlock("",this));
      connect(levelList[i],SIGNAL(levelSelected(QString)),
	      this,SLOT(lvlSelected(QString)));
      layout->addWidget(levelList[i], floor(i/4), i%4);
   }
   layout->addWidget(bacButton, 3, 0);
   setLayout(layout);
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

   switch(diff) {
      case 0:
	 directory->setPath("levels/easy");
	 break;
      case 1:
	 directory->setPath("levels/medium");
	 break;
      case 2:
	 directory->setPath("levels/hard");
	 break;
      default:
	 directory->setPath("levels"); 
   }

   QFileInfoList fileList;
   QStringList filters;
   filters<<"*.txt";
   fileList=directory->entryInfoList(filters);
   list.clear();
   for(int i=0; i<fileList.size(); i++){
      list<<fileList[i].baseName();
   }
   list.removeDuplicates();

   for(int i=0;i<list.size(); i++){
      levelList[i]->changeText(list[i]);
   }
   for(int i = list.size(); i < 12; i++)
      levelList[i]->changeText("");
}

void levelSelector::lvlSelected(QString s) {
   switch(difficulty) {
      case 0:
	 s = "levels/easy/" + s;
	 break;
      case 1:
	 s = "levels/medium/" + s;
	 break;
      case 2:
	 s = "levels/hard/" + s;
	 break;
   }
   s += ".txt";
   emit levelSelected(s);
   emit reset();
}
