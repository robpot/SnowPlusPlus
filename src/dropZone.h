//Empty drop zone header file. 

#ifndef DROPZONE_H
#define DROPZONE_H

#include <QWidget>
#include <QPainter>
#include "dragStorage.h"
#include <QDragEnterEvent>
#include <QPen>

//magnet to hold codeBlocks
class dropZone : public QWidget {
   Q_OBJECT
  public:
   dropZone(QString s, int i, QWidget *p =0);
   void setDragStorage(dragStorage*);
   bool correctness();
   void setPen(QPen);
  protected:
   void paintEvent(QPaintEvent *);
   void dragEnterEvent(QDragEnterEvent *);
   void dragLeaveEvent(QDragLeaveEvent *);
   void dropEvent(QDropEvent *);
   void mousePressEvent(QMouseEvent *);
   void mouseMoveEvent(QMouseEvent *);
   void mouseReleaseEvent(QMouseEvent *);
  private:
   QPen pen;
   int ID;
   QString text,oldtext;
   dragStorage *drag;
   int baseWidth, baseHeight;
   codeBlock *block;
  signals:
   void newSize();
};

#endif
