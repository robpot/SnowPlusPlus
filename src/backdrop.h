//Erin, Jahson, Jesze, Rob, Steven
//Spring 2014 
#ifndef BACKDROP_H
#define BACKDROP_H

#include <QWidget>
#include <QString>
#include <QPainter>

class backdrop :public QWidget{
    Q_OBJECT

public:
   backdrop(int diff, QWidget *parent=0);
   
protected:
   void paintEvent(QPaintEvent *e);
  private:
   int d;
};


#endif
