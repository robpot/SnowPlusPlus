#ifndef GAMEOVERSCREEN_H
#define GAMEOVERSCREEN_H

#include <QWidget>
#include <QPushButton>
#include <QTimer>
#include <QPainter>

class gameOverScreen : public QWidget
{
  Q_OBJECT
public:
  explicit gameOverScreen(QWidget *parent = 0, int base = 0, int timerem = 0, int snowrem = 0);
private:
  QTimer *scoreintimer, *movebaserect, *movetimerect, *movesnowflakerect,*movesnowman;
  QImage snowman,snowflake,scorebanner,backdrop,goodjobbubble;
  QRect *snowmanrect,*snowflakerect,*scorebannerrect,*backdroprect,*speechrect, *speechtextrect;
  QRect *scorerect, *basescorerect, *timeremainingrect, *snowflakeamountrect;
  QString score,goodjobmessage,basescore,timeremaining,snowflakeamount;
  QPushButton* exitscreen;
protected:
  void paintEvent(QPaintEvent *);
public slots:
  void closeAndSaveScore();

};

#endif // GAMEOVERSCREEN_H
