#include "blockPalette.h"

// Construct the blockPalette widget
//
//
// number and block_per_page variables should be determined
// by the parser program, as well as the information for
// the code blocks in the push_back part of the for loop
blockPalette::blockPalette(level * lvl, QWidget *parent) : QWidget(parent){
   setFixedSize(205, 576);
   setAcceptDrops(true);
   top_arrow = new QImage(":/images/resources/arrow.png");
   bottom_arrow = new QImage(":/images/resources/arrow.png");
   *bottom_arrow = bottom_arrow->mirrored(true,true);
   number = 15;
   block_per_page = 7;
   current_page = 1;
   total_pages = (int)ceil((double)number/block_per_page);

   QList<QString> bloks; 
   for(int i=0; i<lvl->ordered.size(); i++){ 
      if(lvl->codeBlocks.find(i) != lvl->codeBlocks.end()){
	 bloks.push_back(lvl->codeBlocks.at(i));
      }
   }

   for(int i=0; i<bloks.size(); i++){
      blocks.push_back(new codeBlock(bloks[i], i, this));
      blocks.last()->setPalettePos(i);
      blocks.last()->move(4, 44+((blocks.last()->height()+4)*i));
      if(i>=block_per_page){
	 blocks.last()->hide();
      }
   }
   
   /*
   blocks.push_back(new codeBlock("cout<<\"Hello World\";", 0, this));
   blocks.last()->setPalettePos(0);
   blocks.last()->move(4,44+((blocks.last()->height()+4)*0));
   if(0>=block_per_page)
      blocks.last()->hide();
   
   blocks.push_back(new codeBlock("return 0;", 1, this));
   blocks.last()->setPalettePos(1);
   blocks.last()->move(4,44+((blocks.last()->height()+4)*1));
   if(1>=block_per_page)
     blocks.last()->hide();
   blocks.push_back(new codeBlock("int x = 312;", 2, this));
   blocks.last()->setPalettePos(2);
   blocks.last()->move(4,44+((blocks.last()->height()+4)*2));
   if(2>=block_per_page)
   blocks.last()->hide();
   */
   page_height = (blocks.last()->height()+4)*block_per_page;
}

// Draws the image on the screen
void blockPalette::paintEvent(QPaintEvent *){
   QPainter painter(this);
   QRect rect(0,0,width(),height());
   QRect top_arr((width()/2)-16,4, top_arrow->width(),top_arrow->height());
   QRect bot_arr((width()/2)-16,height()-36,bottom_arrow->width(),bottom_arrow->height());
   painter.setOpacity(0.8);
   painter.drawImage(rect,QImage(":/images/resources/blockpalette.png"));
   painter.drawImage(top_arr,*top_arrow);
   painter.drawImage(bot_arr,*bottom_arrow);
}

// Determines if the mouse presses the left button on the arrows
// in the palette widget. The page number is changed, and then
// moves the code blocks to represent the correct page.
void blockPalette::mousePressEvent(QMouseEvent *event) {
   if(event->buttons() == Qt::LeftButton)
   {
      if(event->pos().y() < top_arrow->height()+8)
      {
	 if(current_page != 1)
	 {
	    --current_page;
	    setPage(current_page);
	 }
      }
      else if(event->pos().y() > (height()-bottom_arrow->height()-8))
      {
	 if(current_page != total_pages)
	 {
	    ++current_page;
	    setPage(current_page);
	 }
      }
   }
}

// First, the function hides all blocks in the list.
// Next, the function shows the blocks that should
// be shown on the current page.
// Finally, the function moves all blocks in the list
// to be at the correct position for the current page.
//
// Since we were unable to move the blocks based on their
// previous positions, there is no need to make a separate
// function for the final step, as the formula to move blocks
// up and down is exactly the same.
void blockPalette::setPage(int pages) {
   --pages;
   for(int i = 0; i < blocks.size(); i++)
      blocks[i]->hide();
   int i = pages*block_per_page;
   int bpp = (pages*block_per_page)+block_per_page;
   for(i; (i < bpp) && (i < blocks.size()); i++)
      blocks[i]->show();
   for(int i=0; i < blocks.size(); i++)
      blocks[i]->move(4,-(pages*page_height)+(44+((blocks.last()->height()+4)*i)));
}

void blockPalette::resizeList(int x)
{
   blocks[x]->deactivate();
}

void blockPalette::dragEnterEvent(QDragEnterEvent *event)
{
   event->acceptProposedAction();
}

void blockPalette::dropEvent(QDropEvent *event)
{
   qDebug()<<"Drop event!";
   blocks[store->getCurrent()->getPalettePos()]->activate();
}
