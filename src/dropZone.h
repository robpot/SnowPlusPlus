//Empty drop zone header file. 

#ifndef DROPZONE_H
#define DROPZONE_H

#include <QWidget>
#include <QPainter>

//magnet to hold codeBlocks
class dropZone : public QWidget {
   Q_OBJECT
  public:
   dropZone(QWidget *p =0);
  protected:
   void paintEvent(QPaintEvent *);
};

#endif