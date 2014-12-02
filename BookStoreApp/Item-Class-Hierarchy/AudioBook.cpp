#include "AudioBook.h"


bool AudioBook::setAudioFormat(audioFileFormat fileFormat)
{
   this->fileFormat = fileFormat;
   return true;
}

const void AudioBook::DisplayItem()
{
   Book::DisplayItem();
   cout << fileFormat << " ";
}

ostream& operator<<(ostream & os, const AudioBook & audioBookRef)
{
   os << audioBookRef.Name << ";" 
      << audioBookRef.Quantity << ";" 
      << audioBookRef.Price << ";" 
      << audioBookRef.ISBN << ";"
      << audioBookRef.author << ";"
      << audioBookRef.title << ";"
      << Book::getTextForGenre(audioBookRef.genre) << ";"
      << audioBookRef.publisher << ";"
      << audioBookRef.fileFormat << endl;
   return os;
}

const bool AudioBook::operator== (const AudioBook & audioBookRef)
{
   return (this->Name == audioBookRef.Name
      && this->Quantity == audioBookRef.Quantity
      && this->Price == audioBookRef.Price
      && this->ISBN == audioBookRef.ISBN
      && this->author == audioBookRef.author
      && this->title == audioBookRef.title
      && this->genre == audioBookRef.genre
      && this->publisher == audioBookRef.publisher
      && this->fileFormat == audioBookRef.fileFormat);
}

const bool AudioBook::operator!= (const AudioBook & audioBookRef)
{
   return !operator==(audioBookRef);
}