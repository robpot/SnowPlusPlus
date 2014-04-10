#ifndef LEVELSELECTOR_H
#define LEVELSELECTOR_H

#include <QWidget>
#include <QString>
#include <QPainter>
#include <QGridLayout>
#include <QDir>
#include <QStringList>
#include <QFileInfoList>
#include <QPushButton>
#include "levelBlock.h"

class levelSelector :public QWidget {
   Q_OBJECT

public:
   levelSelector(QWidget *parent=0);
public slots:
   void difficultySelected(int);
   void lvlSelected(QString);
protected:
   void paintEvent(QPaintEvent *);
private:
   int difficulty;
   QStringList list;
   QDir *directory;
   QList<levelBlock*> levelList;
   QGridLayout* layout;
   QPushButton* bacButton;
signals:
   void levelSelected(QString);
   void backButton();
   void reset();

};


#endif
