#ifndef SNOWPLUSPLUS_H
#define SNOWPLUSPLUS_H

#include <QWidget>
#include <QString>
#include <QPainter>
#include "blockPalette.h"
#include "codeFrame.h"
#include "messageBox.h"
#include "snowman.h"
#include "backdrop.h"
#include "scorebox.h"
#include "dragStorage.h"


class snowPlusPlus :public QWidget{
    Q_OBJECT

public:
   snowPlusPlus(QWidget *parent=0);

protected:
   void paintEvent(QPaintEvent *);
   void dragEnterEvent(QDragEnterEvent *);
   void dropEvent(QDropEvent *);

private:
   blockPalette* palette;
   codeFrame* frame;
   messageBox* message;
   snowman* snow;
   backdrop* back;
   scorebox* score;
   dragStorage* storage;
   QTime *timeLimit;


};


#endif
