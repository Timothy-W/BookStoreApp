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

ostream& operator<<(ostream& os, const PaperBook& ep){
   os << ep.Name << ";" << ep.Quantity << ";" << ep.Price << ";" << ep.ISBN << ";" << ep.author << ";" <<
      ep.title << ";" << ep.genre << ";" << ep.publisher << ";" << ep.pageCount << ";" << endl;

   return os;
}