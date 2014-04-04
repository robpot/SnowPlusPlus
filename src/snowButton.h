#ifndef SNOWBUTTON_H
#define SNOWBUTTON_H

#include <QLabel>
#include <QMouseEvent>

class snowButton : public QLabel
{
  Q_OBJECT
public:
  snowButton(QWidget *parent = 0, QPixmap* img = NULL, QPixmap* img2 = NULL);
protected:
  void mousePressEvent(QMouseEvent *ev);
  void enterEvent(QEvent *);
  void leaveEvent(QEvent *);
private:
  QPixmap* img1;
  QPixmap* img2;
signals:
  void clicked();
};

#endif // SNOWBUTTON_H
