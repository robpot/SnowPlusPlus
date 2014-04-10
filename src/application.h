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
#include "instructionWrapper.h"
#include "levelChooser.h"
#include "parser.h"

class application :public QWidget{
    Q_OBJECT

public:
   application(QWidget *parent=0);
public slots:
   void hideInstructions();
   void showLevelSelect();
   void levelSelected(QString);
   void gameOver(int,int,int,int);
   void hideGameOver();
private:
   snowPlusPlus* game;
   gameOverWrapper* gameover;
   instructionWrapper *instructions;
   levelChooser* chooser;
   parser* parse;
};


#endif
