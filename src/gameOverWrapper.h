#ifndef GAMEOVERWRAPPER_H
#define GAMEOVERWRAPPER_H

#include <QVBoxLayout>
#include <QWidget>
#include <QGraphicsView>
#include "gameOverScreen.h"

class gameOverWrapper : public QWidget
{
   Q_OBJECT

      public:
   gameOverWrapper(QWidget *parent=0,int base=0,int timerem=0,int snowrem=0,int diff=0);
  private:
   QGraphicsView *view;
   gameOverScreen *screen;

  signals:
   void restart();
   

};

#endif
