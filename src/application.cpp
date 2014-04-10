//application.cpp
#include "application.h"

application::application(QWidget *parent) : QWidget(parent)
{

   setFixedSize(1024,576);
   instructions=new instructionWrapper(this);
   connect(instructions,SIGNAL(close()),this,SLOT(hideInstructions()));
   connect(instructions,SIGNAL(close()),this,SLOT(showLevelSelect()));
   
}
void application::hideInstructions(){
   instructions->hide();
}

void application::showLevelSelect(){
   chooser = new levelChooser(this);
   chooser->show();
   parse = new parser();
   setFixedSize(1024,576);
   connect(chooser, SIGNAL(levelSelected(QString)), parse, SLOT(loadLevel(QString)));
   connect(chooser, SIGNAL(levelSelected(QString)), this, SLOT(levelSelected(QString)));
}

void application::levelSelected(QString s) {
   //it does stuff with the string
   game = new snowPlusPlus(parse->getLevel(),this);
   connect(game,SIGNAL(showGameOver(int,int,int,int)),this, SLOT(gameOver(int,int,int,int)));
   chooser->hide();
   game->show();
}
void application::gameOver(int base, int timerem, int snowrem, int diff){
   gameover=new gameOverWrapper(this,base,timerem,snowrem,diff);
   game->hide();
   gameover->show();
   connect(gameover,SIGNAL(restart()),this,SLOT(hideGameOver()));
   
}
void application::hideGameOver(){
   delete chooser;
   gameover->hide();
   showLevelSelect();
}
