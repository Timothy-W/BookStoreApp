#include "eBook.h"

bool eBook::setFileFormat(eBookFileFormat fileFormat)
{
   this->fileFormat = fileFormat;
   return true;
}

const void eBook::DisplayItem()
{
   Book::DisplayItem();
}

ostream& operator<<(ostream& os, const eBook& ep){
   os << ep.Name << ";" << ep.Quantity << ";" << ep.Price << ";" << ep.ISBN << ";" << ep.author << ";" <<
      ep.title << ";" << ep.genre << ";" << ep.publisher << ";" << ep.fileFormat << endl;
   return os;
}
