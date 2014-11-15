#ifndef AUDIOBOOK_H
#define AUDIOBOOK_H



#include "Book.h"
class AudioBook :
   public Book
{
public:
   AudioBook();
   virtual ~AudioBook();
   virtual void DisplayItem();
};

#endif
