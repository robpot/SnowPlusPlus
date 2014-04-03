//Erin, Jahson, Jesze, Rob, Steven
//Spring 2014 

#ifndef ANIMATIONFRAME_H
#define ANIMATIONFRAME_H

#include <QWidget>
#include <QPainter>

class animationFrame : public QWidget {
   Q_OBJECT
public:
   animationFrame(QWidget *p=0);
protected:
   void paintEvent(QPaintEvent *);
};

#endif
