//Parser.cpp
//compiles information into a level class
#include "parser.h"
#include <QDebug>
#include <QStringList>
#include <QDir>
parser::parser(QString s){
   subParsing = false;
   levelParse = false;
   extraParse = false;
   QStringList tags;
   tags << "<Name>" <<"</Name>"<<"<FixedBlock>"<<"</FixedBlock>"
	<<"<CodeBlock>"<<"</CodeBlock>"<<"<Level>"<<"</Level>"
	<<"<Extras>"<<"</Extras>"<<"<Hints>"<<"</Hints>"
	<<"<Description>"<<"</Description>"
	<<"<Difficulty>"<< "</Difficulty>";
   tagLib = new QStringList(tags);

   QStringList notTags;
   notTags << "<<"<< ">>"<< "<=" <<">=" << "< "<< "> ";

   notTagLib = new QStringList(notTags);
   
   QFile* data =  new QFile();
   //QDir::setCurrent(QDir::currentPath() + "/levels");
   qDebug() << s;
   data->setFileName(s);
   
   if(data->open(QIODevice::ReadWrite | QIODevice::Text))
   {
      //QTextStream *read = new QTextStream(&data);
      QString g(data->readAll());
      data->close();
      parse(g);
   }
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
   //  "<Name>","</Name>","<FixedBlock>","</FixedBlock>",
//	     "<CodeBlock>","</CodeBlock>","<Level>","</Level>"
//	     ,"<Extras>","</Extras>","<Hints>","</Hints>"
//	     ,"<Description>","</Description>"
//	     ,"<Difficulty>", "</Difficulty>"
   if(tag == "<Name>"){
      qDebug() << "<Name Called>";
      lvl.name = goTillEndTag(data,tag,pos,jump);
      qDebug() << lvl.name;
   }
   if((tag == "<FixedBlock>") && subParsing && levelParse){
      qDebug() << goTillEndTag(data,tag,pos,jump);
      //lvl.addToOrder();
      //lvl.addFixed( gotTillEndTag(data,pos,jump));
   }
   if((tag == "<CodeBlock>") && subParsing ){
      if(levelParse){
	 qDebug() << goTillEndTag(data,tag,pos,jump);
	 //lvl.addToOrder();
	 //lvl.addCode(goTillEndTag(data,pos,jump));
      }
      if(extraParse){
	 qDebug() << goTillEndTag(data,tag,pos,jump);
	 //lvl.addToExtraCodeBlocks
      }
   }
   if(tag == "<Level>"){
      qDebug() <<  "Level called";
      QString sub = goTillEndTag(data,tag,pos,jump);
      qDebug() << sub; 
      subParsing = true;
      levelParse = true;
      parse(sub);
      subParsing = false;
      levelParse = false;
      // call sub stuff
   }
   if(tag == "<Extras>" ){
      qDebug() << "Extras called";
      QString sub = goTillEndTag(data,tag,pos,jump);
      subParsing = true;
      extraParse = true;
      parse(sub);
      subParsing = false;
      extraParse = false;
      //subParsing = true;
      //call sub stuff
   }
   if(tag == "<Hints>"){
      //lvl.hints.push_back(goTillEndTag(data,tag,pos,jump));
   }
   if(tag == "<Description>"){
      //lvl.desc = goTillEndTag(data,pos,jump);
   }
   if(tag == "<Difficulty>"){
      lvl.diff =  goTillEndTag(data,tag,pos,jump);
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
	 //qDebug() << "Found: <" << start_of_tag+1;
	 tag = true;
	 start_of_tag++;
      }
      if(data[i] == '>'){
	 //qDebug() << "Found: >" << end_of_tag+1;
	 end_of_tag++;
      }
      
      if(tag == true){
	 parser_tag += data[i];
	 //qDebug() << parser_tag;
      }
      for(int j=0; j<notTagLib->size(); j++){
	 //qDebug() << "J=" << j << notTagLib->size();
	 if(parser_tag == notTagLib->at(j)){
	    //qDebug() << "Rejected: "<<parser_tag;
	    endPos = pos;
	    tag_type  = "FALSE";
	    return false;
	 }
      }
      for(int k=0; k<tagLib->size(); k++){
	 //qDebug() << "K=" << k << tagLib->size();
	 if(parser_tag == tagLib->at(k)){
	    endPos = i;
	    //qDebug() <<"Accepted :" << parser_tag;
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
   //qDebug() << "Start Pos" << i;
   for(int j=i; j<data.size(); j++){
      betweenTags += data[j];
      
      if(data[j] == '<'){
	 if(isThisATag(data,j,k,endTag)){
	    QString compare = tag;
	    compare.insert(1,'/');
	    //qDebug() <<"We Want "<<compare << " We have " << endTag;
	    if(compare == endTag){
	       return cutEnds(betweenTags);
	    }
	 }
      }
   }
   qDebug() <<"Endpos "<< k;
   qDebug() <<"Between size" <<betweenTags.size() << " data size " << data.size();
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
