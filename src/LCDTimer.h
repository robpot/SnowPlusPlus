#ifndef LCDTIMER_H
#define LCDTIMER_H

#include <QTimer>
#include <QLCDNumber>
#include <QTime>

class LCDTimer:public QLCDNumber{
    Q_OBJECT

public:
    LCDTimer(QWidget * parentWidget,int minutes,int seconds);
    QTimer* ticks;
    QTime*  timeValue;
    int getTimeRemaining() {return timePassed;}

public slots:
    void setDisplay();
    void tick();

private:
    int timePassed;
    int min;
    int sec;

};


#endif // LCDTIMER_H
