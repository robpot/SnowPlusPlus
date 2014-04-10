//Erin, Jahson, Jesze, Rob, Steven
//Spring 2014 
//animation.cpp
// This holds the temporary information from the block that
// is being dragged.
//

#include "dragStorage.h"

dragStorage::dragStorage(QWidget *parent) :
  QWidget(parent)
{
  current = NULL;
}

bool dragStorage::setBlock(codeBlock *block)
{
  if(block != NULL)
  {
    
     current = block; 
    
    return 1;
  }
  else
  {
     
    return 0;
  }

}

codeBlock* dragStorage::getCurrent()
{
   
  return current;
}
