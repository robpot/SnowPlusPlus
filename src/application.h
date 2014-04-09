#ifndef APPLICATION_H
#define APPLICATION_H

#include <QWidget>
#include <QString>
#include <QPainter>
#include "blockPalette.h"
#include "codeFrame.h"
#include "messageBox.h"
#include "snowPlusPlus.h"
#include "gameOverWrapper.h"
#include "levelChooser.h"
#include "parser.h"

class application :public QWidget{
    Q_OBJECT

public:
   application(QWidget *parent=0);
public slots:
   void levelSelected(QString);
   void gameOver(int,int,int,int);
private:
   snowPlusPlus* game;
   gameOverWrapper* gameover;
   levelChooser* chooser;
   parser* parse;
};


#endif
