#ifndef CODEBLOCK_H
#define CODEBLOCK_H

#include <QWidget>
#include <QString>
#include <QPainter>
#include <QMouseEvent>

class codeBlock :public QWidget{
    Q_OBJECT

public:
   codeBlock(QString textVal="",int blockId=0, QWidget *parent=0);
   QString getID() { return text; }
   int getPalettePos() { return palette_pos; }
   void setPalettePos(int p) { palette_pos = p; }
protected:
   void paintEvent(QPaintEvent *e);
   void mousePressEvent(QMouseEvent *);
   void mouseReleaseEvent(QMouseEvent *);
   void mouseMoveEvent(QMouseEvent *);
private:
   QString text;
   int palette_pos;
signals:
   void sendUpBlock(codeBlock*);
};


#endif
