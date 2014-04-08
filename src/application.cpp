//application.cpp
#include "application.h"

application::application(QWidget *parent) : QWidget(parent)
{
   /*
     gameover = new gameOverScreen();
     game = new snowPlusPlus(this);
   */
   chooser = new levelChooser(this);
   parse = new parser();
   setFixedSize(1024,576);
   connect(chooser, SIGNAL(levelSelected(QString)), parse, SLOT(loadLevel(QString)));
   connect(chooser, SIGNAL(levelSelected(QString)), this, SLOT(levelSelected(QString)));
   /* 
      gameover->show();
      game->show();
   */
}

void application::levelSelected(QString s) {
   //it does stuff with the string
   game = new snowPlusPlus(parse->getLevel(),this);
   chooser->hide();
   game->show();
}
