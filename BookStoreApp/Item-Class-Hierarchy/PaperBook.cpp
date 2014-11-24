#include "PaperBook.h"

bool PaperBook::setNumberOfPages(int pageCount)
{
   this->pageCount  = pageCount;
   return true;
}

const void PaperBook::DisplayItem()
{
   Book::DisplayItem();
}