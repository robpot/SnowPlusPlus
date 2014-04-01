//application.cpp
#include "application.h"

application::application(QWidget *parent) : QWidget(parent)
{
   /*
  gameover = new gameOverScreen();
  game = new snowPlusPlus(this);
   */
  chooser = new levelChooser(this);
  setFixedSize(1024,576);
  /* 
  gameover->show();
  game->show();
  */
}

void application::levelSelected(QString s) {
   //it does stuff with the string
}
