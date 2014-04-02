//Parser.cpp
//compiles information into a level class
#include "parser.h"
#include <QDebug>
#include <QStringList>
#include <QDir>
parser::parser(QString s){
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
   }
   if(tag == "<FixedBlock>"){
      //lvl.addFixed( gotTillEndTag(data,pos,jump));
   }
   if(tag == "<CodeBlock>"){
      //lvl.addCode(goTillEndTag(data,pos,jump));
   }
   if(tag == "<Level>"){
      // call sub stuff
   }
   if(tag == "<Extras>" ){
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
      qDebug() <<"I= " << i << data.size();
      
      if(data[i] == '<'){
	 tag = true;
	 start_of_tag++;
      }
      if(data[i] == '>'){
	 tag = false;
	 end_of_tag++;
      }
      
      if(tag == true){
	 parser_tag += data[i];
      }
      for(int j=0; j<notTagLib->size(); j++){
	 //qDebug() << "J=" << j << notTagLib->size();
	 if(parser_tag == notTagLib->at(i)){
	    endPos = pos;
	    tag_type  = "FALSE";
	    return false;
	 }
      }
      for(int k=0; k<tagLib->size(); k++){
	 //qDebug() << "K=" << k << tagLib->size();
	 if(parser_tag == tagLib->at(i)){
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
      if(data[i] == '<'){
	 if(isThisATag(data,j,k,endTag)){
	    QString compare = tag;
	    compare.insert(1,'/');
	    if(compare == endTag){
	       return betweenTags;
	    }
	 }
      }
   }
   return "ERROR: "+ tag + " Is Missing " + tag.insert(1,'/');
}
