//codeFrame.cpp
#include "codeFrame.h"
#include <QGridLayout>
#include <cmath>
#include <QLabel>
//Constructor for the code frame. Accepts a list of strings.
//Total space for blocks is 3 columns 7 rows.

//Add a input for dynamic construction later.
//codeFrame::codeFrame(QStringList code , QWidget *parent=0 ): QWidget(parent){
codeFrame::codeFrame(QWidget *parent, dragStorage *s): QWidget(parent){
   setFixedSize(616, 461);

   //codeList = code;
   store = s;
   //****************************
   //Temp code for this Sprint
   for(int q=1; q<4; q++){
      for(int i=1; i<8; i++){
	 QString *j = new QString(i);
	 j->append(" ,");
	 j->append(q);
	 j->append(" this is a test."); 
	 codeList << *j ;
      }
   }

   
   //*****************************

   
   QGridLayout *grid = new QGridLayout();
   for(int i=0; i<codeList.size(); i++){
      zones.push_back(new dropZone(codeList.at(i), i));
      zones.last()->setDragStorage(store);
   }

   int k=0;
   for(int q=1; q<4; q++){
      for(int i=1; i<8; i++){
	 grid->addWidget(zones.at( k ) , i,q);
	 k++;
      }
   }
   
   setLayout(grid);
   
}

void codeFrame::paintEvent(QPaintEvent *){
   QPainter painter(this);
   QRect rect (0,0,width(),height());
   painter.setOpacity(0.8);
   painter.drawImage(rect, QImage(":/images/resources/dropspace.png"));
}
						\
//Requirements for the codeList. include special QStrings to mark empty zones.
//The Grid is built with dropZones, spacers , and lables
void codeFrame::buildGrids(){

   //calc the max number of pages.
   int pg= static_cast<int>(ceil(static_cast<double>(codeList.size())/21.0));  

   //make pages
   for(int q=0;q < pg; q++){
      QGridLayout *page = new QGridLayout();
      //loops through
      for(int i= (q*21) ; i< ( ((q+1)*21) ) ; i++){
	 int row = i % 7;
	 int col = i % 3;
	 if( i > codeList.size()){
	    //make spacer
	    page->addItem(new QSpacerItem(196,64), row, col);
	 }else if( isSpacer(codeList.at(i)) ){
	    //make spacer
	    page->addItem(new QSpacerItem(196,64), row, col);
	 }else if( isLabel(codeList.at(i)) ){
	    //make label
	    page->addWidget(new QLabel(codeList.at(i)), row, col);
	 }else{
	    //drop zone
	    page->addWidget(new dropZone(codeList.at(i),i), row, col);
	 }
      }
      pages.push_back(new QWidget() );
      pages.at(q)->setLayout(page);
   }
}

bool codeFrame::isLabel(const QString &s){
   return s.contains("Lable");
}
bool codeFrame::isSpacer(const QString &s){
   return s.contains("Spacer");   
}

void codeFrame::page(int i){
}




