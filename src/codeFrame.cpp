//Ein, Jahson, Jesze, Rob, Steven
//Spring 2014
//codeFrame.cpp
#include "codeFrame.h"
#include <QVBoxLayout>
#include <cmath>
#include <QDebug>
//Constructor for the code frame. Accepts a list of strings.
//Total space for blocks is 3 columns 7 rows.

//Add a input for dynamic construction later.
codeFrame::codeFrame(level l,QWidget *parent, dragStorage *s): QWidget(parent){
   lvl = l;
   setFixedSize(616, 461);
   //default orientation
   defX = 20;
   defY = 20;
   //codeList = code;
   store = s;
   //used in pages
   //pages.push_back(0);
   curPage = 0;


   for(int i=0; i< lvl.ordered.size(); i++){
      
      if(lvl.codeBlocks.find(i) != lvl.codeBlocks.end()){
	 dropZone *z = new dropZone("Drop Code Here", i,this);
	 z->setDragStorage(store);
	 connect(z, SIGNAL(newSize()), this, SLOT(resize()));
	 zones.insert(i,z);
      }
      if(lvl.fixedBlocks.find(i) != lvl.fixedBlocks.end()){
	 QLabel *r = new QLabel( lvl.fixedBlocks[i] , this);
	 r->setBaseSize(152,12);
	 others.insert(i,r);
      }
   }
   buildPage();
}

// Used for painting the dropspacs and arrows for the codeFrame area.

void codeFrame::paintEvent(QPaintEvent *){
   QPainter painter(this);
   QRect rect (0,0,width(),height());
   botA = new QImage();
   topA = new QImage(":/images/resources/arrow.png");
   
   *botA = topA->mirrored(true,true);
   QRect top( (width()-topA->width()-32), 4, topA->width(), topA->height() );
   QRect bot( (width()-botA->width()-32), height() - botA->height() -4 , botA->width(), botA->height());
   painter.setOpacity(0.8);
   painter.drawImage(rect, QImage(":/images/resources/dropspace.png"));
   painter.drawImage(bot, *botA);
   painter.drawImage(top,*topA);
   
   
}
// used for pressing the arrow to change pages 
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

   
   for(int l=0; l < lvl.ordered.size(); l++){
      
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

   while(i < lvl.ordered.size()){
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
      }else{
	 i = lvl.ordered.size();
      }
   }
}

// changes page up
void codeFrame::pageUp(){
   if(curPage-10 >= 0){
      curPage -= 10;
   }else if(curPage -5 >= 0){
      curPage -= 5;
   }else if(curPage -1 >= 0){
      curPage -= 1;
   }
   buildPage(curPage);
}
//changes page down
void codeFrame::pageDown(){
   //10
   if(curPage+10 < lvl.ordered.size()){
      curPage += 10;
   }else if(curPage +5 < lvl.ordered.size()){
      curPage += 5;
   }else if(curPage +1 < lvl.ordered.size()){
      curPage += 1;
   }
   buildPage(curPage);
}
// resizes page
void codeFrame::resize(){
   buildPage(curPage);
}

void codeFrame::check(){
   bool allright = true;
   QPen pen(Qt::DashDotLine);
   for(int i=0; i<lvl.ordered.size() ; i++){
      if(zones.find(i) != zones.end()){
	 if(zones[i]->correctness()){
	    //set to green color
	    pen.setColor(Qt::darkGreen);
	    zones[i]->setPen(pen);
	    update();
	 }else{
	    allright = false;
	    pen.setColor(Qt::black);
	    zones[i]->setPen(pen);
	    update();
	    //set to red color
	 }
      }
   }
   if(allright){
      emit allCorrect();
      //emit end game?
   }
}
