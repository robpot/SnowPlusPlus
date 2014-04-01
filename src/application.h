#ifndef APPLICATION_H
#define APPLICATION_H

#include <QWidget>
#include <QString>
#include <QPainter>
#include "blockPalette.h"
#include "codeFrame.h"
#include "messageBox.h"
#include "snowPlusPlus.h"
#include "gameOverScreen.h"
#include "levelChooser.h"


class application :public QWidget{
    Q_OBJECT

public:
   application(QWidget *parent=0);
public slots:
   void levelSelected(QString);
private:
   snowPlusPlus* game;
   gameOverScreen* gameover;
   levelChooser* chooser;
};


#endif
