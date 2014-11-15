#pragma once
#include "Book.h"
class AudioBook :
   public Book
{
public:
   AudioBook();
   virtual ~AudioBook();
   virtual void DisplayItem();
};

