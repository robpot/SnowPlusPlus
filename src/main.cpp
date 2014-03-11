#include "application.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  application a;
  a.show();

  return app.exec();
}
