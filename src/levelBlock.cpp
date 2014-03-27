#include "levelBlock.h"

levelBlock::levelBlock(QString textVal, QWidget *parent) : QWidget(parent) {
   levelName = textVal;
}

void levelBlock::paintEvent(QPaintEvent *) {
   QPainter painter(this);
   QRect rect(0,0,width(),height());
   painter.drawText(rect, Qt::AlignCenter,levelName);
}

void levelBlock::mousePressEvent(QMouseEvent *) {
   if(event->buttons() == Qt::LeftButton)
      emit levelSelected(levelName);
}
