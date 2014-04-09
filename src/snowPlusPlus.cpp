//Erin, Jahson, Jesze, Steven
//Spring 2014
//snowPlusPlus.cpp

#include "snowPlusPlus.h"

//builds the sub QWidgets that are displayed for the game. 
snowPlusPlus::snowPlusPlus(level lvl,QWidget *parent) : QWidget(parent){
   setFixedSize(1024,576);
   setAcceptDrops(true);
   timeLimit=new QTime(0,0,30,0);
   storage = new dragStorage(this);
   back = new backdrop(this);
   palette = new blockPalette(lvl,this);
   palette->setDragStorage(storage);
   frame = new codeFrame(lvl,this,storage);
   message = new messageBox(this);
   snow = new snowman(this,timeLimit->minute(),timeLimit->second());
   score = new scorebox(this,timeLimit->minute(),timeLimit->second());
   connect(palette,SIGNAL(sendUpBlock(codeBlock*)),storage,SLOT(setBlock(codeBlock*)));
   connect(snow,SIGNAL(emitMessage(const QString &)),this,SIGNAL(emitMessage(const QString &)));
   connect(this,SIGNAL(emitMessage(const QString &)),message,SLOT(catchMessage(const QString &)));
   connect(score,SIGNAL(gameOver()),message,SLOT(gameEnd()));
   connect(snow, SIGNAL(snowmanClicked()), score, SLOT(snowmanClicked()));
   connect(score,SIGNAL(checkLevel()), frame, SLOT(check()));
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

/*
void snowPlusPlus::gameEnd(){
  QMessageBox::information(this,"Game Over","It's gettin' hot in here ;)",QMessageBox::Ok,0);
}
*/

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
