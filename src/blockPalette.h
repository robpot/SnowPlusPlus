#ifndef BLOCKPALETTE_H
#define BLOCKPALETTE_H

#include <QWidget>
#include <QPainter>
#include "codeBlock.h"

class blockPalette :public QWidget{
    Q_OBJECT

public:
    blockPalette(QWidget *parent=0);
protected:
    // paint event
    void paintEvent(QPaintEvent *);
private:
    QList<codeBlock*> blocks;
};

#endif
