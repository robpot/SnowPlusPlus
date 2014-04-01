#ifndef DIFFICULTYBLOCK_H
#define DIFFICULTYBLOCK_H

#include <QWidget>
#include <QString>
#include <QPainter>
#include <QMouseEvent>

class difficultyBlock :public QWidget {
   Q_OBJECT

public:
   difficultyBlock(QString textVal="", int blockDiff=0, QWidget *parent=0);
protected:
   void paintEvent(QPaintEvent *);
   void mousePressEvent(QMouseEvent *);
private:
   QString text;
   int difficulty;
signals:
   void difficultySelected(int);
};
   
#endif
