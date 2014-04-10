#include "snowFlakes.h"

SnowFlakes::SnowFlakes(int l, QWidget *parent){
   setFixedSize(190,76);
   

   flakeCount= l;
   liveFlake= new QImage();
   liveFlake->load(":images/resources/snowflake.png");
   deadFlake= new QImage();
   deadFlake->load(":images/resources/snowflake_dead.png");
}

void SnowFlakes::paintEvent(QPaintEvent *){
   int x=0,y=0;
   QPainter p(this);
   QRect r(x,y,width()/5,height()/2);
   for(int i=1;i<flakeCount+1;i++){
      p.drawImage(r,*liveFlake);
      x+=width()/5;
     
      if(x>=width()){
	 x=0;
	 y+=height()/2;
      }
      r.setRect(x,y,width()/5,height()/2);
   }
   for(int i=flakeCount+1;i<11;i++){
      p.drawImage(r,*deadFlake);
      x+=width()/5;

      if(x>=width()){
	 x=0;
	 y+=height()/2;
      }
      r.setRect(x,y,width()/5,height()/2);
   }
   
}

void SnowFlakes::loseFlake(int f){
   flakeCount=f;
   update();
}
