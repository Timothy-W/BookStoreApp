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

ostream & operator<<(ostream & os, const eBook& eBookRef)
{
   os << "\nName: " << eBookRef.Name
      << "\nQuantity: " << eBookRef.Quantity
      << "\nPrice: " << eBookRef.Price
      << "\nISBN: " << eBookRef.ISBN
      << "\nAuthor: " << eBookRef.author
      << "\nTitle: " << eBookRef.title
      << "\nGenre: " << Book::getTextForGenre(eBookRef.genre)
      << "\nPublisher: " << eBookRef.publisher
      << "\nFile Format: " << eBook::eBookFileFormatText(eBookRef.fileFormat);
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

const eBook & eBook::operator= (const eBook & eBookRef)
{
   if (this != &eBookRef)
   {
      this->Name = eBookRef.Name;
      this->Quantity = eBookRef.Quantity;
      this->Price = eBookRef.Price;
      this->ISBN = eBookRef.ISBN;
      this->author = eBookRef.author;
      this->title = eBookRef.title;
      this->genre = eBookRef.genre;
      this->publisher = eBookRef.publisher;
      this->fileFormat = eBookRef.fileFormat;
   }
   return *this;
}