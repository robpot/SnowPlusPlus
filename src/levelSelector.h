#ifndef LEVELSELECTOR_H
#define LEVELSELECTOR_H

#include <QWidget>
#include <QString>
#include <QPainter>
#include <QGridLayout>
#include <QDir>
#include <QStringList>
#include <QFileInfoList>
#include "difficultyBlock.h"

class levelSelector :public QWidget {
   Q_OBJECT

public:
   levelSelector(QWidget *parent=0);
public slots:
   void difficultySelected(int);
protected:
   void paintEvent(QPaintEvent *);
private:
   QList<*levelBlock> levelList;
   int difficulty;
   QStringList list;
   QDir directory;
signals:
   void levelSelected(QString);
};


#endif
