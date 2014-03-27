//Parser.h
//Compiles information from a text file into a level class.

#ifndef PARSER_H
#define PARSER_H
#include <QList>
#include <QString>
#include <QFile>
#include <QTextStream>
#include "level.h"
class level;

class parser {
  public:
   parser(QString s);
   level getLevel();
  private:
   level lvl;
   void parse(QTextStream *r);
  protected:
};

#endif
