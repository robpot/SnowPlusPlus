//level.h
//A struct to hold unique level information. Use by the codePallet and codeFrame to build a level.

#ifndef LEVEL_H
#define LEVEL_H
#include <map>
#include <QString>
#include <QList>
#include <utility>
#include <QMap>

class level {
  public:
   level();
   //Difficulty
   QString diff;
   //Level Name
   QString name;
   //Ordered List (Defines the order of apperance)
   QList<QString> ordered;
   //Map of code blocks
   QMap<int,QString> codeBlocks;
   //Map of fixed blocks
   QMap<int,QString> fixedBlocks;
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
