#include "levelChooser.h"

levelChooser::levelChooser(QWidget *parent) : QWidget(parent) {
   diffSelector = new difficultySelector(this);
   levelSelector = new levelSelector(this);
   connect(diffSelector, SIGNAL(difficultySelected(int)), levelSelector, SLOT(difficultySelected(int)));
}

