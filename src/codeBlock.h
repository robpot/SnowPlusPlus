#ifndef CODEBLOCK_H
#define CODEBLOCK_H

#include <QWidget>
#include <QString>
#include <QPainter>

class codeBlock :public QWidget{
    Q_OBJECT

public:
   codeBlock(QString textVal="",int blockId=0, QWidget *parent=0);
   
protected:
   void paintEvent(QPaintEvent *e);

private:
   QString text;
};


#endif
