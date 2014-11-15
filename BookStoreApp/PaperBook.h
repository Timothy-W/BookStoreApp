#ifndef PAPERBOOK_H
#define PAPERBOOK_H

#include "Book.h"
class PaperBook :
   public Book
{
public:
   PaperBook();
   virtual ~PaperBook();
   virtual void DisplayItem();
};

#endif