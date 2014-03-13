//codeBlock.cpp

#include "snowPlusPlus.h"

snowPlusPlus::snowPlusPlus(QWidget *parent) : QWidget(parent){
   setFixedSize(1024,576);
   storage = new dragStorage(this); 
   timeLimit=new QTime(0,0,30,0);
   back = new backdrop(this);
   palette = new blockPalette(this);
   frame = new codeFrame(this,storage);
   message = new messageBox(this);
   snow = new snowman(this,timeLimit->minute(),timeLimit->second());
   score = new scorebox(this,timeLimit->minute(),timeLimit->second());
   connect(palette,SIGNAL(sendUpBlock(codeBlock*)),
           storage,SLOT(setBlock(codeBlock*)));
   back->show();
   back->move(0,0);
   palette->show();
   palette->move(0,0);
   frame->show();
   frame->move(205,0);
   message->show();
   message->move(205,461);
   snow->show();
   snow->move(820,268);
   score->show();
   score->move(820,0);
}

void snowPlusPlus::paintEvent(QPaintEvent *){
   QPainter painter(this);
   painter.drawRect(1,1 , width()-2, height()-2);
}
