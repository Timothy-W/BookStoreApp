#pragma once
#include "Book.h"
class PaperBook :
   public Book
{
public:
   PaperBook();
   virtual ~PaperBook();
   virtual void DisplayItem();
};

