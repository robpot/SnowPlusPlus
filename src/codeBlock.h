#ifndef CODEBLOCK_H
#define CODEBLOCK_H

#include <QWidget>

class CodeBlock :public QWidget{
    Q_OBJECT

public:
    CodeBlock(QString textVal="",int blockId=0, QWidget *parent=0);
};


#endif
