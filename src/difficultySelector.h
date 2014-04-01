#ifndef DIFFICULTYSELECTOR_H
#define DIFFICULTYSELECTOR_H

#include <QWidget>
#include <QString>
#include <QPainter>
#include <QGridLayout>
#include <QLabel>
#include "difficultyBlock.h"

class difficultySelector :public QWidget {
   Q_OBJECT

public:
   difficultySelector(QWidget *parent=0);
protected:
   void paintEvent(QPaintEvent *e);
private:
   QList<difficultyBlock*> diffList;
signals:
   void difficultySelected(int);
};


#endif
