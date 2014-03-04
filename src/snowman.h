#ifndef SNOWMAN_H
#define SNOWMAN_H

#include <QWidget>
#include <QString>
#include <QPainter>

class snowman :public QWidget{
    Q_OBJECT

public:
   snowman(QString textVal="",int blockId=0, QWidget *parent=0);
   
protected:
   void paintEvent(QPaintEvent *e);
};


#endif
