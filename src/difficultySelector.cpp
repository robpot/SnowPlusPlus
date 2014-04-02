//difficultyselector.cpp
#include "difficultySelector.h"

difficultySelector::difficultySelector(QWidget *parent) : QWidget(parent){
   setFixedSize(1024, 576);
   diffList.push_back(new difficultyBlock("Winter (easy): ", 0, this));
   diffList.push_back(new difficultyBlock("Spring (medium): ", 1, this));
   diffList.push_back(new difficultyBlock("Summer (hard): ", 2, this));
   QGridLayout *layout = new QGridLayout();
   QSpacerItem *litem = new QSpacerItem(700, height()/4);
   layout->addItem(litem, 0, 0);
   layout->addWidget(diffList[0], 1, 0);
   layout->addWidget(diffList[1], 2, 0);
   layout->addWidget(diffList[2], 3, 0);
   setLayout(layout);
   for(int i = 0; i < 3; i++) {
      connect(diffList[i], SIGNAL(difficultySelected(int)), this, SIGNAL(difficultySelected(int)));
   }
}

//Maybe should change the backdrop to something else? Or should we
// keep is as winter?
void difficultySelector::paintEvent(QPaintEvent *) {
   QPainter painter(this);
   QRect rect(0,0,width(),height());
   QRect rect2(112, 5, 800, 150);
   painter.drawImage(rect,QImage(":/images/resources/backdrop_winter.png"));
   painter.drawImage(rect2, QImage(":/images/resources/difficultychoose.png"));
   
}

void difficultySelector::mousePressEvent(QMouseEvent *event) {
   //  qDebug() << "BLAAAAAAAAAH";
}
