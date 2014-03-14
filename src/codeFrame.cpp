//codeFrame.cpp
#include "codeFrame.h"
#include <QVBoxLayout>
#include <cmath>
#include <QDebug>
//Constructor for the code frame. Accepts a list of strings.
//Total space for blocks is 3 columns 7 rows.

//Add a input for dynamic construction later.
//codeFrame::codeFrame(QStringList code , QWidget *parent=0 ): QWidget(parent){
codeFrame::codeFrame(QWidget *parent, dragStorage *s): QWidget(parent){
   setFixedSize(616, 461);
   //default orientation
   defX = 20;
   defY = 20;
   //codeList = code;
   store = s;
   //used in pages
   pages.push_back(0);
   curPage = 0;
   
   //****************************
   //Temp code for this Sprint
   codeList << "Label int Main" << "Spacer";
   for(int i=1; i<40; i++){
      QString *j = new QString(i);
      j->append(" ,");
      j->append(" this is a test."); 
      codeList << *j ;
   }
   
   //**************************

   for(int i=0; i<codeList.size(); i++){
      if(isLabel(codeList.at(i))){
	 QString l = codeList.at(i);
	 QLabel *r = new QLabel( l.remove("Label") , this);
	 r->setBaseSize(152,12);
	 others.insert(std::pair<int,QLabel*> (i,r));
      }
      else if(isSpacer(codeList.at(i))){
	 QLabel *e = new QLabel("", this);
	 e->setBaseSize(152,12);
	 others.insert(std::pair<int,QLabel*> (i,e));
      }else{
	 dropZone *z = new dropZone(codeList.at(i), i,this);
	 z->setDragStorage(store);
	 connect(z, SIGNAL(newSize()), this, SLOT(resize()));
	 zones.insert(std::pair<int, dropZone*> (i,z));
      }
   }
   buildPage();
   
}

void codeFrame::paintEvent(QPaintEvent *){
   QPainter painter(this);
   QRect rect (0,0,width(),height());
   botA = new QImage();
   topA = new QImage(":/images/resources/arrow.png");
   
   *botA = topA->mirrored(true,true);
   QRect top( (width()/2), 4, topA->width(), topA->height() );
   QRect bot( (width()/2), height() - botA->height() -4 , botA->width(), botA->height());
   painter.setOpacity(0.8);
   painter.drawImage(rect, QImage(":/images/resources/dropspace.png"));
   painter.drawImage(bot, *botA);
   painter.drawImage(top,*topA);
   
   
}

void codeFrame::mousePressEvent(QMouseEvent *e){
   int ypos = e->pos().y();
   if(e->button() == Qt::LeftButton){
      if(ypos < topA->height()+8){
	 pageUp();	 
      }
      if(ypos > (height() - botA->height() -8)){
	 pageDown();
      }
   }
}
						
//Requirements for the codeList. include special QStrings to mark empty zones.
//The Grid is built with dropZones, spacers , and lables
void codeFrame::buildPage(int start){
   //contains text, and dropzones
   // need an ordered list for show.

   
   for(int l=0; l<codeList.size(); l++){
      if(zones.find(l) != zones.end()){
	 zones[l]->hide();
      }
      if(others.find(l) != others.end()){
	 others[l]->hide();
      }
   }


   int Y = defY;
   int X = defX;
   int i = start;
   bool morePages = false;
   
   while(i<codeList.size() && !morePages){
      if(Y < 400){ //Show
	 if(others.find(i) != others.end()){
	    others[i]->move(X,Y);
	    others[i]->show();
	    Y = Y + others[i]->height() + 2;
	    i++;
	 }else if(zones.find(i) != zones.end()){
	    zones[i]->move(X,Y);
	    zones[i]->show();
	    Y = Y  +zones[i]->height() + 2;
	    i++;
	 }
	 
      }else{ //Hide
	 pages.push_back(i);
	 morePages = true;
	 /*
	 for(int l=0; l<start; l++){
	    if( zones.find(l) != zones.end())
	       zones[l]->hide();
	    if(others.find(l) != others.end())
	       others[l]->hide();
	 }
	 for(int l=i; l<codeList.size(); l++){
	    if(zones.find(l) != zones.end())
	       zones[l]->hide();
	    if(others.find(l) != others.end())
	       others[l]->hide();
	       }*/
      }
   }
}


bool codeFrame::isLabel(const QString &s){
   return s.contains("Label");
}
bool codeFrame::isSpacer(const QString &s){
   return s.contains("Spacer");   
}

void codeFrame::pageUp(){
   if(curPage-1 >= 0){
      curPage--;
      buildPage(curPage);
   }
}
void codeFrame::pageDown(){
   if( (curPage+1 < pages.size()) && (curPage+1 < codeList.size()) ){
      curPage++;
      buildPage(curPage);
   }
   
}
void codeFrame::resize(){
   
   buildPage(pages[curPage]);
}
