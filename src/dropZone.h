//Empty drop zone header file. 

#ifndef DROPZONE_H
#define DROPZONE_H

#include <QWidget>
#include <QPainter>
#include "dragStorage.h"
#include <QDragEnterEvent>

//magnet to hold codeBlocks
class dropZone : public QWidget {
   Q_OBJECT
  public:
   dropZone(QString s, int i, QWidget *p =0);
   void setDragStorage(dragStorage*);
  protected:
   void paintEvent(QPaintEvent *);
   void dragEnterEvent(QDragEnterEvent *);
   void dropEvent(QDropEvent *);
  private:
   int ID;
   QString text;
   dragStorage *drag;
   int baseWidth, baseHeight;
};

#endif
