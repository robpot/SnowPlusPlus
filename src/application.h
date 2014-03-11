#ifndef APPLICATION_H
#define APPLICATION_H

#include <QWidget>
#include <QString>
#include <QPainter>
#include "blockPalette.h"
#include "codeFrame.h"
#include "messageBox.h"
#include "snowPlusPlus.h"


class application :public QWidget{
    Q_OBJECT

public:
   application(QWidget *parent=0);
private:
   snowPlusPlus* game;

};


#endif
