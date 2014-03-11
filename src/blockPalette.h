#ifndef BLOCKPALETTE_H
#define BLOCKPALETTE_H

#include <QWidget>
#include <QPainter>
#include <math.h>
#include <QDebug>
#include <QMouseEvent>
#include "codeBlock.h"

class blockPalette :public QWidget{
    Q_OBJECT

public:
    blockPalette(QWidget *parent=0);
public slots:
    void removeFromList(codeBlock*);
protected:
    // paint event
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void setPage(int);
private:
    QList<codeBlock*> blocks;
    QImage* top_arrow;
    QImage* bottom_arrow;
    int current_page;
    int total_pages;
    int number;
    int block_per_page;
    int page_height;
signals:
    void sendUpBlock(codeBlock*);
};

#endif
