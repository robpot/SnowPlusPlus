//codeFrame.cpp
#include "codeFrame.h"
#include <QGridLayout>
//Add a input for dynamic construction later.
//codeFrame::codeFrame(QStringList codeList , QWidget *parent=0 ): QWidget(parent){
codeFrame::codeFrame(QWidget *parent): QWidget(parent){
   setFixedSize(616, 461);

   QStringList codeList;
   for(int i=0; i<6; i++){
      QString *j = new QString(i);
      j->append(" this is a test."); 
      codeList << *j ;
   }
   QGridLayout *grid = new QGridLayout();
   for(int i=0; i<codeList.size(); i++){
      zones.push_back(new dropZone(codeList.at(i), i));
   }

   for(int i=0; i<zones.size(); i++){
      grid->addWidget(zones.at(i));
   }
   
   setLayout(grid);
}

void codeFrame::paintEvent(QPaintEvent *){
   QPainter painter(this);
   QRect rect (0,0,width(),height());
   painter.setOpacity(0.8);
   painter.drawImage(rect, QImage(":/images/resources/dropspace.png"));
}

//Need to make string with drop zones.
//The string will be a layout.
//The dropzones will be a layout.



