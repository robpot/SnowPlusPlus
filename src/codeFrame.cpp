//codeFrame.cpp
#include "codeFrame.h"
#include <QVBoxLayout>
#include <cmath>
#include <QLabel>
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
   std::pair<int,int> pageOne(0,0);
   pages.push(pageOne);
   
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

<<<<<<< HEAD
=======
   /*
   QGridLayout *grid = new QGridLayout();
>>>>>>> f07a587be8f3f8c160f67580cba579d569813f9f
   for(int i=0; i<codeList.size(); i++){
      if(!isLabel(codeList.at(i)) && !isSpacer(codeList.at(i))){
	 zones.push_back(new dropZone(codeList.at(i), i,this));
	 zones.last()->setDragStorage(store);
	 connect(zones.last(), SIGNAL(newSize()), this, SLOT(resize()));
	 
      }
   }
<<<<<<< HEAD
   buildPage();
=======
   
   setLayout(grid);
   */

   zones.push_back(new dropZone(codeList.at(0), 0, this));
   zones.last()->setDragStorage(store);
   zones.last()->show();
>>>>>>> f07a587be8f3f8c160f67580cba579d569813f9f
}

void codeFrame::paintEvent(QPaintEvent *){
   QPainter painter(this);
   QRect rect (0,0,width(),height());
   painter.setOpacity(0.8);
   painter.drawImage(rect, QImage(":/images/resources/dropspace.png"));
   QImage *botA = new QImage(":/images/reosurces/arrow.png");
   QImage *topA = new QImage(":/images/resources/arrow.png");
   *botA = botA->mirrored(true,true);

   QRect top( (width()/2), 4, topA->width(), topA->height() );
   QRect bot( (width()/2), (height() - botA->height() ) -4, botA->width(), botA->height());
   
   painter.drawImage(top,*topA);
   painter.drawImage(bot, *botA);
   
}

void codeFrame::mousePressEvent(QMouseEvent *e){
  /* if(e->button() == Qt::LeftMouseButton){
      if(e->pos()){
      }
      if(){
      }
      }
  */
}
						\
//Requirements for the codeList. include special QStrings to mark empty zones.
//The Grid is built with dropZones, spacers , and lables
void codeFrame::buildPage(int i, int k){
   //contains text, and dropzones
   // need an ordered list for show.
   int Y = defY;
   int X = defX;
   for(; i< codeList.size(); i++){
      if(Y < 400){
	 if(isLabel(codeList.at(i))){
	    QString l = codeList.at(i);
	    QLabel *r = new QLabel( l.remove("Label") , this);
	    r->setBaseSize(152,12);
	    r->move(X,Y);
	    r->show();
	    Y = Y + r->height() + 2;
	 }else if(isSpacer(codeList.at(i))){
	    QLabel *e = new QLabel("", this);
	    e->setBaseSize(152,12);
	    e->move(X,Y);
	    e->show();
	    Y = Y + e->height() + 2;
	 }else {
	    zones.at(k)->move(X,Y);
	    zones.at(k)->show();
	    Y = Y  +zones.at(k)->height() + 2;
	    k++;
	 }
      }else{
	 //other pages made
	 std::pair<int,int> page(i,k);
	 pages.push(page);
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
   if(pages.size() > 0){
      if(pages.size() != 1){
	 pages.pop();
      }
      std::pair<int,int> p(pages.top());
      buildPage(p.first, p.second);
   }
}
void codeFrame::pageDown(){
   if(pages.size() > 1){
      std::pair<int,int> p(pages.top());
      buildPage(p.first, p.second);
   }
   
}
void codeFrame::resize(){
   buildPage();
}
