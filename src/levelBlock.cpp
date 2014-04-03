#include "levelBlock.h"
#include <QFont>

levelBlock::levelBlock(QString textVal, QWidget *parent) : QWidget(parent) {
   levelName = textVal;
}

void levelBlock::paintEvent(QPaintEvent *) {
   QPainter painter(this);
   QRect rect(0,0,width(),height());
   painter.drawImage(rect, QImage(":/images/resources/block.png"));
   painter.setFont(QFont("Times", 42));
   painter.drawText(rect, Qt::AlignCenter,levelName);
}

void levelBlock::mousePressEvent(QMouseEvent* event) {
   if((levelName != "") && (event->buttons() == Qt::LeftButton))
      emit levelSelected(levelName);
}

void levelBlock::changeText(QString s) {
   levelName = s;
   update();
}
