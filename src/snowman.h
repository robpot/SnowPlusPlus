#ifndef SNOWMAN_H
#define SNOWMAN_H

#include <QWidget>
#include <QString>
#include <QPainter>
#include <QTimer>
#include <QImage>
#include <QMessageBox>

class snowman :public QWidget{
    Q_OBJECT

public:
   snowman(QWidget *parent=0);
//   void loadPic(const QString &name);
public slots:
   void nextSnowman();
   
protected:
   void paintEvent(QPaintEvent *e);

private:
   QTimer *timer;
   QImage *image;
   int count;
   QStringList *strs;
};


#endif
