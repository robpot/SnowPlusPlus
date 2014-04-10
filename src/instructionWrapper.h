#ifndef INSTRUCTIONWRAPPER_H
#define INSTRUCTIONWRAPPER_H

#include <QVBoxLayout>
#include <QWidget>
#include <QGraphicsView>
#include "instructionScreen.h"

class instructionWrapper : public QWidget
{
   Q_OBJECT

  public:
   instructionWrapper(QWidget *parent=0);
  private:
   QGraphicsView *view;
   instructionScreen *screen;
  signals:
   void close();

};

#endif
