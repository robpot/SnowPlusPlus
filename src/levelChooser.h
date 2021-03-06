#ifndef LEVELCHOOSER_H
#define LEVELCHOOSER_H

#include <QWidget>
#include <QString>
#include <QPainter>
#include "difficultySelector.h"
#include "levelSelector.h"

class levelChooser : public QWidget {
   Q_OBJECT

public:
   levelChooser(QWidget *parent = 0);
public slots:
   void diffSelected(int);
   void backButton();
   void reset();
private:
   difficultySelector* diffSelector;
   levelSelector* levSelector;
   bool dSelected;
   void showHide();
signals:
   void levelSelected(QString);
};

#endif
