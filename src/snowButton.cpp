#include "snowButton.h"

snowButton::snowButton(QWidget* parent, QPixmap* img, QPixmap* img_2) : QLabel(parent)
{
  img1 = img;
  img2 = img_2;
  setPixmap(*img);
}

void snowButton::mousePressEvent(QMouseEvent *ev)
{
  if(ev->buttons() == Qt::LeftButton)
    emit clicked();
}

void snowButton::enterEvent(QEvent *)
{
  if(img2 != NULL)
    setPixmap(*img2);
}

void snowButton::leaveEvent(QEvent *)
{
  if(img1 != NULL)
    setPixmap(*img1);
}
