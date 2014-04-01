#ifndef DIFFICULTYSELECTOR_H
#define DIFFICULTYSELECTOR_H

#include <QWidget>
#include <QString>
#include <QPainter>
#include <QGridLayout>
#include <QLabel>
#include <QLayoutItem>
#include <QSpacerItem>
#include "difficultyBlock.h"
#include <QDebug>
#include <QMouseEvent>

class difficultySelector :public QWidget {
   Q_OBJECT

public:
   difficultySelector(QWidget *parent=0);
protected:
   void paintEvent(QPaintEvent *e);
   void mousePressEvent(QMouseEvent *);
private:
   QList<difficultyBlock*> diffList;
signals:
   void difficultySelected(int);
};


#endif
