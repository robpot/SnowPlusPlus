//difficultyselector.cpp
#include "difficultySelector.h"

difficultySelector::difficultySelector(QWidget *parent) : QWidget(parent){
   setFixedSize(1024, 576);
   diffList.push_back(new difficultyBlock("Winter (easy): ", 0, this));
   diffList.push_back(new difficultyBlock("Spring (medium): ", 1, this));
   diffList.push_back(new difficultyBlock("Summer (hard): ", 2, this));
   QGridLayout *layout = new QGridLayout();
   QLabel *title = new QLabel("Choose a Difficulty: ", this);
   layout->addWidget(title, 0, 0);
   layout->addWidget(diffList[0], 1, 0);
   layout->addWidget(diffList[1], 2, 0);
   layout->addWidget(diffList[2], 3, 0);
   setLayout(layout);
}

//Maybe should change the backdrop to something else? Or should we
// keep is as winter?
void difficultySelector::paintEvent(QPaintEvent *) {
   QPainter painter(this);
   QRect rect(0,0,width(),height());
   painter.drawImage(rect,QImage(":/images/resources/backdrop_winter.png"));
   
}
