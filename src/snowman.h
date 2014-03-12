#ifndef SNOWMAN_H
#define SNOWMAN_H

#include <QWidget>
#include <QString>
#include <QPainter>
#include <QTimer>
#include <QTime>
#include <QImage>
#include <QMessageBox>

class snowman :public QWidget{
    Q_OBJECT

public:
   snowman(QWidget *parent=0, int minutes=2, int seconds=0);
public slots:
   void nextSnowman();
   
protected:
   void paintEvent(QPaintEvent *e);

private:
   QTime *time;
   QTimer *timer;
   QImage *image;
   int count;
   QStringList *strs;
};


#endif
