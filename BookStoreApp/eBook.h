#pragma once
#include "Book.h"
class eBook :
   public Book
{
public:
   eBook();
   virtual ~eBook();
   virtual void DisplayItem();
};

