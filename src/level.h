//level.h
//A struct to hold unique level information. Use by the codePallet and codeFrame to build a level.

#ifndef LEVEL_H
#define LEVEL_H
#include <map>
#include <QString>
#include <QList>
#include <utility>

class level {
  public:
   level();
   //Difficulty
   QString diff;
   //Level Name
   QString name;
   //Orderd List (Defines the order of apperance)
   QList<QString> ordered;
   //Map of code blocks
   std::map<int,QString> codeBlocks;
   //Map of fixed blocks
   std::map<int,QString> fixedBlocks;
   //Time
   int time;
   //Base score
   int baseS;
   //Bonus Score
   int bonusS;
   //Snowman's timed hints
   QList<QString> hints;
};

#endif
