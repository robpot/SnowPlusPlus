#include "dragStorage.h"
#include <QDebug>


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
