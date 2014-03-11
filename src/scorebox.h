#ifndef SCOREBOX_H
#define SCOREBOX_H

#include <QWidget>
#include <QString>
#include <QPainter>
#include <QTimer>
#include <QTime>
#include <QLabel>
#include <QGridLayout>
#include <QLCDNumber>
#include "LCDTimer.h"

class scorebox :public QWidget{
    Q_OBJECT

public:
    scorebox(QWidget *parent=0,int min=1,int sec=0);

protected:
    void paintEvent(QPaintEvent *e);

private:
    LCDTimer *timer;

};

#endif
