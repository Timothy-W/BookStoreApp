#include "PaperBook.h"

bool PaperBook::setNumberOfPages(int pageCount)
{
   this->pageCount  = pageCount;
   return true;
}

const void PaperBook::DisplayItem()
{
   Book::DisplayItem();
   cout << pageCount << " ";
}

ostream & operator<<(ostream & os, const PaperBook& paperBookRef)
{
   os << "\nName: " << paperBookRef.Name
      << "\nQuantity: " << paperBookRef.Quantity
      << "\nPrice: " << paperBookRef.Price
      << "\nISBN: " << paperBookRef.ISBN
      << "\nAuthor: " << paperBookRef.author
      << "\nTitle: " << paperBookRef.title
      << "\nGenre: " << Book::getTextForGenre(paperBookRef.genre)
      << "\nPublisher: " << paperBookRef.publisher
      << "\nPage Count: " << paperBookRef.pageCount;
   return os;
}

const bool PaperBook::operator== (const PaperBook & paperBookRef)
{
   return (this->Name == paperBookRef.Name
      && this->Quantity == paperBookRef.Quantity
      && this->Price == paperBookRef.Price
      && this->ISBN == paperBookRef.ISBN
      && this->author == paperBookRef.author
      && this->title == paperBookRef.title
      && this->genre == paperBookRef.genre
      && this->publisher == paperBookRef.publisher
      && this->pageCount == paperBookRef.pageCount);
}

const bool PaperBook::operator!= (const PaperBook & paperBookRef)
{
   return !operator==(paperBookRef);
}

const PaperBook & PaperBook::operator= (const PaperBook & paperBookRef)
{
   if (this != &paperBookRef)
   {
      this->Name = paperBookRef.Name;
      this->Quantity = paperBookRef.Quantity;
      this->Price = paperBookRef.Price;
      this->ISBN = paperBookRef.ISBN;
      this->author = paperBookRef.author;
      this->title = paperBookRef.title;
      this->genre = paperBookRef.genre;
      this->publisher = paperBookRef.publisher;
      this->pageCount = paperBookRef.pageCount;
   }
   return *this;
}