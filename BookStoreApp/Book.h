#ifndef BOOK_H
#define BOOK_H


#include "Product.h"
class Book : public Product
{
protected:
   int ISBN;
   string Author;
   string Title;
   genreType Genre;
   string publisher;


public:
   Book();
   virtual ~Book();
   virtual void DisplayItem();
protected:
   int ISBN;
   string Author;
   string Title;
   genreType Genre;
   string publisher;
};

#endif
