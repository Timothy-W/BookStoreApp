#ifndef PAPERBOOK_H
#define PAPERBOOK_H

#include "Book.h"
class PaperBook : public Book
{
private:
   int pageCount;

public:
   //Constructors
   PaperBook() : Book(), pageCount(0) {}
   PaperBook(string Name, int Quantity, double Price, int ISBN, string author, string title,
                                     genreType genre, string publisher, int pageCount) : 
                        Book(Name, Quantity, Price, ISBN, author, title, genre, publisher), pageCount(pageCount) {}

   //Destructor
   virtual ~PaperBook() {}

   //Mutators and Accessors
   int getNumberOfPages() { return pageCount; }

   bool setNumberOfPages(int pageCount);

   virtual const void DisplayItem();
};

#endif