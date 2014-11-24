#include "Book.h"

bool Book::setISBN(int ISBN)
{
   this->ISBN = ISBN;
   return true;
}

bool Book::setAuthor(string author)
{
   this->author = author;
   return true;
}

bool Book::setTitle(string title)
{
   this->title = title;
   return true;
}

bool Book::setGenre(genreType genre)
{
   this->genre = genre;
   return true;
}

bool Book::setPublisher(string publisher)
{
   this->publisher = publisher;
   return true;
}

const string Book::getTextForEnum(genreType genre)
{
   switch (genre)
   {
   case SCIENCE_FICTION:
      return "SCience Fiction";
   case MYSTERY:
      return "Mystery";
   case HORROR:
      return "Horror";
   case ROMANCE:
      return "Romance";
   default:
      return "Unknown";
   }
}

const void Book::DisplayItem()
{
   Product::DisplayItem();
   cout << ISBN << " " << author << " " << title << " " << genre << " " << publisher << " " << endl;
}