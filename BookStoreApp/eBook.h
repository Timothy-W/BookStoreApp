#ifndef EBOOK_H
#define EBOOK_H

#include "Book.h"
class eBook :
   public Book
{
public:
   eBook();
   virtual ~eBook();
   virtual void DisplayItem();
};

#endif