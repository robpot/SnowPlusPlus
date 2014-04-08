//Erin, Jahson, Jesze, Rob, Steven
//Spring 2014

#ifndef CODEBLOCK_H
#define CODEBLOCK_H

#include <QWidget>
#include <QString>
#include <QPainter>
#include <QDrag>
#include <QMimeData>
#include <QMouseEvent>
#include <QBitmap>

class codeBlock :public QWidget{
    Q_OBJECT

public:
   codeBlock(QString textVal="",int blockId=0, QWidget *parent=0);
   codeBlock(codeBlock &, QWidget *parent=0);
   QString getID() { return text; }
   int getPalettePos() { return palette_pos; }
   void setPalettePos(int p) { palette_pos = p; }
   int getNumLines() { return numLines; }
   void deactivate();
   void activate();
   bool isActive(){return active;}
   int getIDNum(){return ID;}
protected:
   void paintEvent(QPaintEvent *e);
   void mousePressEvent(QMouseEvent *);
   void mouseReleaseEvent(QMouseEvent *);
   void mouseMoveEvent(QMouseEvent *);
private:
   QString text;
   int palette_pos;
   int numLines;
   int ID;
   bool active;
signals:
   void sendUpBlock(codeBlock*);
   void triggerResize(int);
};


#endif
