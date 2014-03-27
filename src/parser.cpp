//Parser.cpp
//compiles information into a level class
#include "parser.h"
#include <QDebug>
#include <QStringList>
parser::parser(QString s){
   QFile data(s);
   if(data.open(QFile::ReadOnly))
   {
      QTextStream *read = new QTextStream(&data);
      parse(read);
   }
   
}

level parser::getLevel(){
   return lvl;
}

//large loop to read each line
//mini loops for each tag read.
void parser::parse(QTextStream *r){
   //while(!r->atEnd()){
   bool done = false;
   while(!done){
      QString look = r->readLine();

      QString test = "<Name>HELLO KIDS</Name>";
      QStringList list;
      int pos =0;
      QRegExp nrx("<Name>([a-zA-Z0-9]+)</Name>");
      while((pos = nrx.indexIn(test, pos)) != -1){
	 list << nrx.cap(1);
	 pos += nrx.matchedLength();
      }
      qDebug() << list;
      done = true;

      /*
      QRegExp drx("");
      QRegExp difrx("");
      QRegExp lrx("");
      QRegExp erx("");

      QRegExp cbrx("");
      QRegExp fbrx("");
      QRegExp hrx("");
      */
      //level 0 nest: Name, Description, Difficulty, Level, Extras.
      //level 1 nest: CodeBlock, Fixed Block, Hints
      
   }
}
