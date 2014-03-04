#ifndef SCOREBOX_H
#define SCOREBOX_H

#include <QWidget>
#include <QString>
#include <QPainter>

class scorebox :public QWidget{
    Q_OBJECT

public:
   scorebox(QWidget *parent=0);
   
protected:
   void paintEvent(QPaintEvent *e);
};


#endif
