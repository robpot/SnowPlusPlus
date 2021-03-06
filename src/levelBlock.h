#ifndef LEVELBLOCK_H
#define LEVELBLOCK_H

#include <QWidget>
#include <QString>
#include <QPainter>
#include <QMouseEvent>

class levelBlock : public QWidget {
   Q_OBJECT

public:
   levelBlock(QString textVal="", QWidget *parent=0);
   void changeText(QString);
protected:
   void paintEvent(QPaintEvent *);
   void mousePressEvent(QMouseEvent *);
private:
   QString levelName;
signals:
   void levelSelected(QString);
};



#endif
