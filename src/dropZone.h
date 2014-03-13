//Empty drop zone header file. 

#ifndef DROPZONE_H
#define DROPZONE_H

#include <QWidget>
#include <QPainter>
#include <QDragEnterEvent>

//magnet to hold codeBlocks
class dropZone : public QWidget {
   Q_OBJECT
  public:
   dropZone(QString s, int i, QWidget *p =0);
  protected:
   void paintEvent(QPaintEvent *);
   void dragEnterEvent(QDragEnterEvent *);
   void dropEvent(QDropEvent *);
   int ID;
   QString text;
};

#endif
