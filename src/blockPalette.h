#ifndef BLOCKPALETTE_H
#define BLOCKPALETTE_H

#include <QWidget>
#include "codeBlock.h"

class BlockPalette :public QWidget{
    Q_OBJECT

public:
    BlockPalette(QWidget *parent=0);

private:
    QList<CodeBlock*> blocks;
};

#endif
