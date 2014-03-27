#ifndef LEVELCHOOSER_H
#define LEVELCHOOSER_H

#include <QWidget>
#include <QString>
#include <QPainter>
#include "difficultySelector.h"
#include "levelSelector.h"

class levelChooser :public QWidget {
   Q_OBJECT

public:
   levelChooser(QWidget *parent = 0);
private:
   difficultySelector* diffSelector;
   levelSelector* levelSelector;
signals:
   void levelSelected(QString);
}

#endif
