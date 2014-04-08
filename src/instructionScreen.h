#ifndef INSTRUCTIONSCREEN_H
#define INSTRUCTIONSCREEN_H

#include "snowButton.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QIcon>

class instructionScreen : public QGraphicsScene
{
  Q_OBJECT
public:
  instructionScreen(QWidget *parent = 0);
private:
  QTimer *snowmantimer;
  QTimer *tic;
  QGraphicsPixmapItem *backdrop, *snowman, *speech1, *speech2, *speech3, *speech4, *frame;
  snowButton* continuewithtut, *skiptut;
  int stage;
  int snowmanstartx,snowmanstarty,snowmanfinalx,snowmanfinaly;

signals:
  void close();
public slots:
  void moveSnowman();
  void progress();
  void exitInstructions();

};

#endif // INSTRUCTIONSCREEN_H
