#ifndef BLOCKPALETTE_H
#define BLOCKPALETTE_H

#include <QWidget>
#include <QPainter>
#include <math.h>
#include <QDebug>
#include <QMouseEvent>
#include "codeBlock.h"
#include "dragStorage.h"

class blockPalette :public QWidget{
    Q_OBJECT

public:
    blockPalette(QWidget *parent=0);
    void setDragStorage(dragStorage* s) { store = s; }
    codeBlock* getBlocks(int i) { return blocks[i]; }
public slots:
    void resizeList(int);
    //   void activateBlock(int);
protected:
    // paint event
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void dragEnterEvent(QDragEnterEvent *);
    void dropEvent(QDropEvent *);
    void setPage(int);
private:
    dragStorage* store;
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
