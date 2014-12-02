#include "eBook.h"

bool eBook::setFileFormat(eBookFileFormat fileFormat)
{
   this->fileFormat = fileFormat;
   return true;
}

const string eBook::eBookFileFormatText(eBookFileFormat fileFormat)
{
   switch (fileFormat)
   {
   case PDF:
      return "PDF";
   case EPUB:
      return "ePub";
   default:
      return "Unknown";
   }
}

const void eBook::DisplayItem()
{
   Book::DisplayItem();
   cout << eBookFileFormatText(fileFormat) << " ";
}

ostream& operator<<(ostream& os, const eBook& ep){
   os << ep.Name << ";" << ep.Quantity << ";" << ep.Price << ";" << ep.ISBN << ";" << ep.author << ";" <<
      ep.title << ";" << ep.genre << ";" << ep.publisher << ";" << ep.fileFormat << endl;
   return os;
}

const bool eBook::operator== (const eBook & eBookRef)
{
   return (this->Name == eBookRef.Name
      && this->Quantity == eBookRef.Quantity
      && this->Price == eBookRef.Price
      && this->ISBN == eBookRef.ISBN
      && this->author == eBookRef.author
      && this->title == eBookRef.title
      && this->genre == eBookRef.genre
      && this->publisher == eBookRef.publisher
      && this->fileFormat == eBookRef.fileFormat);
}

const bool eBook::operator!= (const eBook & eBookRef)
{
   return !operator==(eBookRef);
}