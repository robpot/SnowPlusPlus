#include <QWidget>
#include <QGridLayout>
#include <QPainter>
#include <QImage>

#ifndef SNOWFLAKE_H
#define SNOWFLAKE_H

class SnowFlakes :public QWidget{
   Q_OBJECT
      
  public:
   SnowFlakes(int l=10,QWidget *parent=0);
   void loseFlake(int f);
  private:
   
    int flakeCount;
    QImage *liveFlake, *deadFlake;
  protected:
    void paintEvent(QPaintEvent *e);
      
};
#endif
