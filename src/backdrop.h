#ifndef BACKDROP_H
#define BACKDROP_H

#include <QWidget>
#include <QString>
#include <QPainter>

class backdrop :public QWidget{
    Q_OBJECT

public:
   backdrop(QWidget *parent=0);
   
protected:
   void paintEvent(QPaintEvent *e);
};


#endif
