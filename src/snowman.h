#ifndef SNOWMAN_H
#define SNOWMAN_H

#include <QWidget>
#include <QString>
#include <QPainter>

class snowman :public QWidget{
    Q_OBJECT

public:
   snowman(QWidget *parent=0);
   
protected:
   void paintEvent(QPaintEvent *e);
};


#endif
