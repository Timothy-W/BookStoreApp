#ifndef AUDIOBOOK_H
#define AUDIOBOOK_H

#include "Book.h"

enum audioFileFormat { UNKNOWN_AUDIO, MP3 };

class AudioBook : public Book
{
protected:
   audioFileFormat fileFormat;

public:
   AudioBook() : Book(), fileFormat(UNKNOWN_AUDIO) {}
   AudioBook(string Name, int Quantity, double Price, int ISBN, string author, string title,
                        genreType genre, string publisher, audioFileFormat fileFormat) : 
                        Book(Name, Quantity, Price, ISBN, author, title, genre, publisher), fileFormat(fileFormat) {}

   //Destructor
   virtual ~AudioBook();

   //Mutators and Accessors
   audioFileFormat getAudioFormat();
   void setAudioFormat(audioFileFormat fileFormat);

   static const string audioFileFormatText(audioFileFormat fileFormat);
   virtual const void DisplayItem();

   friend ostream & operator<< (ostream & os, const AudioBook & audioBookRef);
   const bool operator== (const AudioBook & audioBookRef);
   const bool operator!= (const AudioBook & audioBookRef);
   const AudioBook & operator= (const AudioBook & audioBookRef);
};

#endif
