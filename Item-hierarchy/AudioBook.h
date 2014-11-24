#ifndef AUDIOBOOK_H
#define AUDIOBOOK_H

#include "Book.h"

enum audioFileFormat { UNKNOWN_AUDIO, MP3 };

class AudioBook : public Book
{
protected:
   int numberOfDiscs;
   int playTimeInSeconds;
   audioFileFormat fileFormat;

public:
   AudioBook::AudioBook() : Book(), fileFormat(UNKNOWN_AUDIO) {}
   AudioBook::AudioBook(string Name, int Quantity, double Price, int ISBN, string author, string title,
                        genreType genre, string publisher, audioFileFormat fileFormat) : 
                        Book(Name, Quantity, Price, ISBN, author, title, genre, publisher), fileFormat(fileFormat) {}

   //Destructor
   virtual ~AudioBook() {}

   //Mutators and Accessors
   audioFileFormat getAudioFormat() { return fileFormat; }

   bool setAudioFormat(audioFileFormat fileFormat);

   virtual const void DisplayItem();
};

#endif
