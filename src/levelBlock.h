#ifndef LEVELBLOCK_H
#define LEVELBLOCK_H

#include <QWidget>
#include <QString>
#include <QPainter>

class levelBlock : public QWidget {
   Q_OBJECT

public:
   levelBlock(QString textVal="", QWidget *parent=0);
protected:
   void paintEvent(QPaintEvent *);
   void mousePressEvent(QMouseEvent *);
private:
   QString levelName;
signals:
   void levelSelected(QString);
};



#endif
