#ifndef LCDTIMER_H
#define LCDTIMER_H

#include <QTimer>
#include <QLCDNumber>
#include <QTime>

class LCDTimer:public QLCDNumber{
    Q_OBJECT

public:
    LCDTimer(QWidget * parentWidget,int minutes,int seconds);
    void setTime(int min,int sec);
    QTimer* timer;
    QTime*  timeValue;

public slots:
    void setDisplay();

};


#endif // LCDTIMER_H
