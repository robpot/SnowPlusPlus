#include "levelChooser.h"

levelChooser::levelChooser(QWidget *parent) : QWidget(parent) {
   diffSelector = new difficultySelector(this);
   levSelector = new levelSelector(this);
   connect(diffSelector, SIGNAL(difficultySelected(int)), levSelector, SLOT(difficultySelected(int)));
}

