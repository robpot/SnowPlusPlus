//application.cpp
#include "application.h"

application::application(QWidget *parent) : QWidget(parent)
{
  game = new snowPlusPlus(this);
  setFixedSize(1024,576);
  game->show();
}
