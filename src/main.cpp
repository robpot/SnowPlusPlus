#include "application.h"
#include <QApplication>
#include "parser.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  application a;
  a.show();

  //TEST********
  //parser p("testlevel.txt");
  
  
  return app.exec();
}
