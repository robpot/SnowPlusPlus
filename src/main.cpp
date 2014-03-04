#include "application.h"
#include "snowPlusPlus.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  snowPlusPlus a;
  a.show();

  return app.exec();
}
