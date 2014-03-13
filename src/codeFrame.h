//codeFrame.h
#ifndef CODEFRAME_H
#define CODEFRAME_H

#include <QWidget>
#include <QPainter>
#include "dropZone.h"
#include "dragStorage.h"

class codeFrame :public QWidget{
   Q_OBJECT
      
      public:
   //codeFrame(QStringList code, QWidget *parent=0);
   codeFrame(QWidget *parent = 0, dragStorage *s =0);
 protected:
   void paintEvent(QPaintEvent *e);
   //void 

  private:
   QList<dropZone*> zones;
   QStringList codeList;
   QList<QWidget*> pages;
   void buildGrids();
   void page(int i);
   bool isLabel(const QString & s);
   bool isSpacer(const QString & s);
   dragStorage *store;
};

#endif
