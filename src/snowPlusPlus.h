//Erin, Jahson, Jesze, Steven
//Spring 2014
//Header for the snowPlusPlus class. This class is responsable for generating the level that is playable.
//snowPlusPlus.h
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
#include "level.h"
#include <QMessageBox>


class snowPlusPlus :public QWidget{
    Q_OBJECT

public:
   snowPlusPlus(level lvl, QWidget *parent=0);
//public slots:
//   void gameEnd();
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

signals:
   void emitMessage(const QString &);

};


#endif
