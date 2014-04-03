//Parser.h
//Compiles information from a text file into a level class.

#ifndef PARSER_H
#define PARSER_H
#include <QObject>
#include <QList>
#include <QString>
#include <QFile>
#include <QTextStream>
#include "level.h"
class level;

class parser : public QObject{
   Q_OBJECT
  public:
   parser(QObject *o =0);
   level getLevel();
  private:
   level lvl;
   bool subParsing, levelParse, extraParse; 
   QStringList *tagLib;
   QStringList *notTagLib;
   void parse(QString r);
   void tagHandler(QString data, QString tag, int pos, int & jump);
   bool isThisATag(QString data, int pos, int &endPos, QString &tag_type);
   bool tagLibary(QString compare, bool &notATag);
   QString goTillEndTag(QString data,QString tag, int i, int &k);
   QString cutEnds(QString data);
   //void parse();
  protected:
   public slots:
   void loadLevel(QString file);
};

#endif
