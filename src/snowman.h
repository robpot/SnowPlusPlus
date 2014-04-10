//Erin, Jahson, Jesze, Steven
//Spring 2014
//The snowman class is an animation which melts over time. The snowman class
//is also clickable and is designed to give hints to the user. 
//snowman.h
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
   void sendMessage(const QString &str);
   void sendMessage();
protected:
   void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *e);
private:
   QTime *time;
   QTimer *timer;
   QImage *image;
   int count;
   QStringList *strs;
signals:
   void emitMessage(const QString &);
   void snowmanClicked();
};


#endif
