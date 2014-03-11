//codeFrame.h
#ifndef CODEFRAME_H
#define CODEFRAME_H

#include <QWidget>
#include <QPainter>

class codeFrame :public QWidget{
   Q_OBJECT
      
public:
   codeFrame(QWidget *parent = 0);
 protected:
   void paintEvent(QPaintEvent *e);
};

#endif
