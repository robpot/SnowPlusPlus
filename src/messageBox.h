#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <QWidget>
#include <QString>
#include <QPainter>

class messageBox :public QWidget{
    Q_OBJECT

public:
   messageBox(QWidget *parent=0);
public slots:
   void catchMessage(const QString &str);
   
protected:
   void paintEvent(QPaintEvent *e);

private:
   QString msg;
};


#endif
