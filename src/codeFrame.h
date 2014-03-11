//codeFrame.h
#ifndef CODEFRAME_H
#define CODEFRAME_H

#include <QWidget>
#include <QPainter>
#include "dropZone.h"

class codeFrame :public QWidget{
   Q_OBJECT
      
      public:
   //codeFrame(QStringList codeList, QWidget *parent=0);
   codeFrame(QWidget *parent = 0);
 protected:
   void paintEvent(QPaintEvent *e);

  private:
   QList<dropZone*> zones;
};

#endif
