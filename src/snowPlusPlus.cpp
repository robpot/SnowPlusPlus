//Erin, Jahson, Jesze, Steven
//Spring 2014
//snowPlusPlus.cpp

#include "snowPlusPlus.h"

//builds the sub QWidgets that are displayed for the game. 
snowPlusPlus::snowPlusPlus(level lvl,QWidget *parent) : QWidget(parent){
   setFixedSize(1024,576);
   setAcceptDrops(true);
   if(lvl.diff=="Easy")
      difficulty=0;
   if(lvl.diff=="Medium")
      difficulty=1;
   if(lvl.diff=="Hard")
      difficulty=2;
   back = new backdrop(difficulty,this);
   timeLimit=new QTime(0,lvl.min,lvl.sec,0);
   storage = new dragStorage(this);
   palette = new blockPalette(lvl,this);
   palette->setDragStorage(storage);
   frame = new codeFrame(lvl,this,storage);
   message = new messageBox(this);
   snow = new snowman(this,timeLimit->minute(),timeLimit->second());
   score = new scorebox(this,timeLimit->minute(),timeLimit->second());
   goScreen = NULL;
   baseScore = difficulty*500 + 500;
   connect(palette,SIGNAL(sendUpBlock(codeBlock*)),storage,SLOT(setBlock(codeBlock*)));
   connect(snow,SIGNAL(emitMessage(const QString &)),this,SIGNAL(emitMessage(const QString &)));
   connect(this,SIGNAL(emitMessage(const QString &)),message,SLOT(catchMessage(const QString &)));
   connect(score,SIGNAL(gameOver(const int&, const int&)),this,SLOT(gameEnd(const int&, const int&)));
   connect(snow, SIGNAL(snowmanClicked()), score, SLOT(snowmanClicked()));
   connect(score,SIGNAL(checkLevel()), frame, SLOT(check()));
   connect(frame, SIGNAL(allCorrect()), score ,SLOT(allCorrect()));
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

//Draws an outline for the whole applcation. 
void snowPlusPlus::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.drawRect(1,1 , width()-2, height()-2);
}


void snowPlusPlus::gameEnd(const int &timeRem, const int &snowRem){
   emit showGameOver(0,timeRem,snowRem,difficulty);
}


//Allows dragEnterEvents
void snowPlusPlus::dragEnterEvent(QDragEnterEvent *event)
{
   event->acceptProposedAction();
}

//Allows drop events, participates int the drag and drop 
void snowPlusPlus::dropEvent(QDropEvent *event)
{
    palette->getBlocks(storage->getCurrent()->getPalettePos())->activate();
}
