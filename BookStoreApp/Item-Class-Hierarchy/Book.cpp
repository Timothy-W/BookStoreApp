#include "Book.h"

int Book::getISBN()
{ 
   return ISBN;
}

string Book::getAuthor() 
{ 
   return author;
}

string Book::getTitle()
{ 
   return title;
}

genreType Book::getGenre() 
{ 
   return genre;
}

string Book::getPublisher()
{ 
   return publisher; 
}

bool Book::setISBN(int ISBN)
{
   if (ISBN < 0)
      return false;

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

const string Book::getTextForGenre(genreType genre)
{
   switch (genre)
   {
   case SCIENCE_FICTION:
      return "Science Fiction";
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
   cout << ISBN << " " << author << " " << title << " " << getTextForGenre(genre) << " " << publisher << " ";
}