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
   QStringList *tagLib;
   QStringList *notTagLib;
   void parse(QString r);
   void tagHandler(QString data, QString tag, int pos, int & jump);
   bool isThisATag(QString data, int pos, int &endPos, QString &tag_type);
   bool tagLibary(QString compare, bool &notATag);
   QString goTillEndTag(QString data,QString tag, int i, int &k);
   //void parse();
  protected:
};

#endif
