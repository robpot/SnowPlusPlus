//codeFrame.h
#ifndef CODEFRAME_H
#define CODEFRAME_H

#include <QWidget>
#include <QPainter>
#include "dropZone.h"
#include "dragStorage.h"
#include <stack>
#include <utility>
#include <map>
#include <QLabel>
#include <vector>
class codeFrame :public QWidget{
   Q_OBJECT
      
      public:
   //codeFrame(QStringList code, QWidget *parent=0);
   codeFrame(QWidget *parent = 0, dragStorage *s =0);
 protected:
   void paintEvent(QPaintEvent *e);
   void mousePressEvent(QMouseEvent *e);  
   
  private:
   std::map<int,dropZone * > zones;
   QStringList codeList;
   void buildPage(int start =0);
   bool isLabel(const QString & s);
   bool isSpacer(const QString & s);
   void pageUp();
   void pageDown();
   dragStorage *store;
   int defX, defY;
   QWidget *inner;
   QImage *botA, *topA;
   //first is itterator of codeList
   //second if itterator of zones
   std::map<int,QLabel*> others; 
   std::vector<int> pages;
   int curPage;
   public slots:
   void resize();
};

#endif
