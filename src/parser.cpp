//Erin, Jahson, Jesze, Steven
//Spring 2014
//Parser.cpp
#include "parser.h"
#include <QDebug>
#include <QStringList>
#include <QDir>
parser::parser(QObject *o) : QObject(o){
   subParsing = false;
   levelParse = false;
   extraParse = false;
   QStringList tags;
   tags << "<Name>" <<"</Name>"<<"<FixedBlock>"<<"</FixedBlock>"
	<<"<CodeBlock>"<<"</CodeBlock>"<<"<Level>"<<"</Level>"
	<<"<Extras>"<<"</Extras>"<<"<Hints>"<<"</Hints>"
	<<"<Description>"<<"</Description>"
	<<"<Difficulty>"<< "</Difficulty>"
        <<"<Min>"<<"</Min>"<<"<Sec>"<<"</Sec>";
   tagLib = new QStringList(tags);

   QStringList notTags;
   notTags << "<<"<< ">>"<< "<=" <<">=" << "< "<< "> ";

   notTagLib = new QStringList(notTags);
   
   
   //parse();
   
   
}

level parser::getLevel(){
   return lvl;
}

//large loop to read each line
//mini loops for each tag read.
void parser::parse(QString data){
//void parser::parse(){
   for(int i=0; i<data.size(); i++){
      QString tag;
      if(data[i] == '<'){
	 int jump=i;
	 if(isThisATag(data,i,jump,tag)){
	    i = jump;
	    int jump2 =i;
	    tagHandler(data,tag,i,jump2);
	    i = jump2;
	 }
      }
   }

   
   //QString look = r->readAll();
   
   /*
   QStringList descList;
   pos =0;
   QRegExp drx("<Desc>([a-zA-Z0-9 ]+)</Desc>");
   while((pos = drx.indexIn(r, pos)) != -1){
      descList << drx.cap(1);
      pos += drx.matchedLength();
   }
   */
   
}


void parser::tagHandler(QString data, QString tag, int pos, int &jump){
   if(tag == "<Name>"){
     
      lvl.name = goTillEndTag(data,tag,pos,jump);
     
   }
   if((tag == "<FixedBlock>") && subParsing && levelParse){
      QString fixed = goTillEndTag(data,tag,pos,jump);
      lvl.ordered.push_back(fixed);
      lvl.fixedBlocks.insert(lvl.ordered.size()-1, fixed);
     
   }
   if((tag == "<CodeBlock>") && subParsing ){
      if(levelParse){
	 QString code = goTillEndTag(data,tag,pos,jump);
	 lvl.ordered.push_back(code);
	 lvl.codeBlocks.insert(lvl.ordered.size()-1, code);
	
      }
      if(extraParse){ // extras not being used this sprint
	 //qDebug() << goTillEndTag(data,tag,pos,jump);
      }
   }
   if(tag == "<Level>"){
     
      QString sub = goTillEndTag(data,tag,pos,jump);
     
      subParsing = true;
      levelParse = true;
      parse(sub);
      subParsing = false;
      levelParse = false;
     
   }
   if(tag == "<Extras>" ){
     
      QString sub = goTillEndTag(data,tag,pos,jump);
      subParsing = true;
      extraParse = true;
      parse(sub);
      subParsing = false;
      extraParse = false;
          //call sub stuff
   }
   if(tag == "<Hints>"){
      lvl.hints.push_back(goTillEndTag(data,tag,pos,jump));
   }
   if(tag == "<Description>"){
      lvl.desc = goTillEndTag(data,tag,pos,jump);
   }
   if(tag == "<Difficulty>"){
      lvl.diff =  goTillEndTag(data,tag,pos,jump);
   }
   if(tag == "<Min>"){
      lvl.min = goTillEndTag(data, tag, pos, jump).toInt();
   }
   if(tag =="<Sec>"){
      lvl.sec = goTillEndTag(data, tag, pos, jump).toInt();
   }
}


bool parser::isThisATag(QString data, int pos,int & endPos, QString & tag_type){
   bool tag= false;
   int start_of_tag = 0;
   int end_of_tag = 0;
   QString parser_tag;

   QString compare;
   
   for(int i=pos; i<data.size(); i++){
      compare +=data[i];   
      
      if(data[i] == '<'){

	 tag = true;
	 start_of_tag++;
      }
      if(data[i] == '>'){

	 end_of_tag++;
      }
      
      if(tag == true){
	 parser_tag += data[i];

      }
      for(int j=0; j<notTagLib->size(); j++){
	
	 if(parser_tag == notTagLib->at(j)){
	  
	    endPos = pos;
	    tag_type  = "FALSE";
	    return false;
	 }
      }
      for(int k=0; k<tagLib->size(); k++){

	 if(parser_tag == tagLib->at(k)){
	    endPos = i;
	 
	    tag_type = parser_tag;
	    return true;
	 }
      }
      if(end_of_tag > 1 || start_of_tag > 1){
	 endPos = pos;
	 tag_type = "FALSE";
	 return false;
      }
     
   }
   endPos = pos;
   tag_type = "FALSE";
   return false;
}

QString parser::goTillEndTag(QString data, QString tag, int i, int &k){
   QString betweenTags;
   k =i;
   QString endTag;
 
   for(int j=i; j<data.size(); j++){
      betweenTags += data[j];
      
      if(data[j] == '<'){
	 if(isThisATag(data,j,k,endTag)){
	    QString compare = tag;
	    compare.insert(1,'/');
	  
	    if(compare == endTag){
	       return cutEnds(betweenTags);
	    }
	 }
      }
   }
  
   return "ERROR: "+ tag + " Is Missing " + tag.insert(1,'/');
}

QString parser::cutEnds(QString data){
   if(data.endsWith('<')){
      data.chop(1);
   }
   if(data.startsWith('>')){
      data.remove(0,1);
   }
   return data;
}

void parser::loadLevel(QString file){
   QFile* data =  new QFile();
   QDir::setCurrent(QDir::currentPath());
  
   data->setFileName(file);
   
   if(data->open(QIODevice::ReadWrite | QIODevice::Text))
   {
  
      QString g(data->readAll());
      data->close();
      parse(g);
   }
}
