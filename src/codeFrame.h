//codeFrame.h
#ifndef CODEFRAME_H
#define CODEFRAME_H

#include <QWidget>
#include <QPainter>
#include "dropZone.h"
#include "dragStorage.h"
#include <stack>
#include <utility>


class codeFrame :public QWidget{
   Q_OBJECT
      
      public:
   //codeFrame(QStringList code, QWidget *parent=0);
   codeFrame(QWidget *parent = 0, dragStorage *s =0);
 protected:
   void paintEvent(QPaintEvent *e);
   void mousePressEvent(QMouseEvent *e);  
   
  private:
   QList<dropZone*> zones;
   QStringList codeList;
   void buildPage(int k =0, int i=0);
   bool isLabel(const QString & s);
   bool isSpacer(const QString & s);
   void pageUp();
   void pageDown();
   dragStorage *store;
   int defX, defY;
   QWidget *inner;
   //first is itterator of codeList
   //second if itterator of zones
   std::stack< std::pair<int,int> > pages;
   public slots:
   void resize();
};

#endif
