#include "levelChooser.h"

levelChooser::levelChooser(QWidget *parent) : QWidget(parent) {
   dSelected = false;
   diffSelector = new difficultySelector(this);
   levSelector = new levelSelector(this);
   connect(diffSelector, SIGNAL(difficultySelected(int)), levSelector, SLOT(difficultySelected(int)));
   connect(diffSelector, SIGNAL(difficultySelected(int)), this, SLOT(diffSelected(int)));
   connect(levSelector, SIGNAL(levelSelected(QString)), this, SIGNAL(levelSelected(QString)));
   connect(levSelector, SIGNAL(backButton()), this, SLOT(backButton()));
   showHide();
}

void levelChooser::diffSelected(int) {
   dSelected = true;
   showHide();
}

void levelChooser::backButton() {
   dSelected = false;
   showHide();
}

void levelChooser::showHide() {
   if (!dSelected) {
      diffSelector->show();
      levSelector->hide();
   } else {
      levSelector->show();
      diffSelector->hide();
   }
}
