#ifndef GAMEOVERSCREEN_H
#define GAMEOVERSCREEN_H

#include <QWidget>
#include <QPushButton>
#include <QTimer>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

class gameOverScreen : public QGraphicsScene
{
  Q_OBJECT
public:
  explicit gameOverScreen(QWidget *parent = 0, int base = 0, int timerem = 0, int snowrem = 0, int dif = 0);
private:
  QTimer *tic;
  QGraphicsPixmapItem *snowman,*snowflake,*scorebanner,*backdrop,*goodjobbubble;
  QGraphicsTextItem *scorerect, *basescorerect, *timeremainingrect, *snowflakeamountrect;
  QString score,goodjobmessage,basescore,timeremaining,snowflakeamount;
  QPushButton* exitscreen;
  int snowmanstartx,snowmanfinalx;
  int snowmanstarty,snowmanfinaly;

  int scorestartx,scorestarty;
  int scorefinalx,scorefinaly;
  int totalscore;

  bool step1done, step2done, step3done;

protected:
  void paintEvent(QPaintEvent *);
signals:
  void sendexit();
public slots:
  void closeAndSaveScore();
  void animate();

};

#endif // GAMEOVERSCREEN_H
