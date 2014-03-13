#ifndef DRAGSTORAGE_H
#define DRAGSTORAGE_H

#include <QWidget>
#include <QMouseEvent>
#include "codeBlock.h"

class dragStorage : public QWidget
{
  Q_OBJECT
public:
  dragStorage(QWidget *parent = 0);
public slots:
  bool setBlock(codeBlock*);
  codeBlock* getCurrent();
private:
  codeBlock* current;

};

#endif // DRAGSTORAGE_H
