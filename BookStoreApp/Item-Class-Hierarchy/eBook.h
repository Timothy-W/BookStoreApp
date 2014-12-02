#ifndef EBOOK_H
#define EBOOK_H

#include "Book.h"

enum eBookFileFormat { UNKNOWN_EBOOK, PDF, EPUB };

class eBook : public Book
{
private:
   eBookFileFormat fileFormat;

public:
   //Constructors
   eBook() : Book(), fileFormat(UNKNOWN_EBOOK) {}
   eBook(string Name, int Quantity, double Price,
      int ISBN, string author, string title,
      genreType genre, string publisher, eBookFileFormat fileFormat)
      : Book(Name, Quantity, Price, ISBN, author, title, genre, publisher), fileFormat(fileFormat) {}

   //Destructor
   virtual ~eBook() {}
   
   //Mutators and Accessors
   eBookFileFormat getFileFormat() { return fileFormat; }
   bool setFileFormat(eBookFileFormat fileFormat);
   
   static const string eBookFileFormatText(eBookFileFormat fileFormat);
   virtual const void DisplayItem();

   friend ostream & operator<< (ostream& os, const eBook & c);
   const bool operator== (const eBook & eBookRef);
   const bool operator!= (const eBook & eBookRef);
};

#endif