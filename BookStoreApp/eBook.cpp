#include "eBook.h"

bool eBook::setFileFormat(eBookFileFormat fileFormat)
{
   this->fileFormat = fileFormat;
   return true;
}

const void eBook::DisplayItem()
{
   Book::DisplayItem();
}

