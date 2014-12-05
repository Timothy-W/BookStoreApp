#include "AudioBook.h"

audioFileFormat AudioBook::getAudioFormat()
{ 
   return fileFormat;
}

void AudioBook::setAudioFormat(audioFileFormat fileFormat)
{
   this->fileFormat = fileFormat;
}

const string AudioBook::audioFileFormatText(audioFileFormat fileFormat)
{
   switch (fileFormat)
   {
   case MP3:
      return ".MP3";
   default:
      return "Unknown";
   }
}

const void AudioBook::DisplayItem()
{
   Book::DisplayItem();
   cout << audioFileFormatText(fileFormat) << " ";
}

ostream & operator<<(ostream & os, const AudioBook& audioBookRef)
{
   os << "\nName: " << audioBookRef.Name
      << "\nQuantity: " << audioBookRef.Quantity
      << "\nPrice: " << audioBookRef.Price
      << "\nISBN: " << audioBookRef.ISBN
      << "\nAuthor: " << audioBookRef.author
      << "\nTitle: " << audioBookRef.title
      << "\nGenre: " << Book::getTextForGenre(audioBookRef.genre)
      << "\nPublisher: " << audioBookRef.publisher
      << "\nFile Format: " << AudioBook::audioFileFormatText(audioBookRef.fileFormat);
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

const AudioBook & AudioBook::operator= (const AudioBook & audioBookRef)
{
   if (this != &audioBookRef)
   {
      this->Name = audioBookRef.Name;
      this->Quantity = audioBookRef.Quantity;
      this->Price = audioBookRef.Price;
      this->ISBN = audioBookRef.ISBN;
      this->author = audioBookRef.author;
      this->title = audioBookRef.title;
      this->genre = audioBookRef.genre;
      this->publisher = audioBookRef.publisher;
      this->fileFormat = audioBookRef.fileFormat;
   }
   return *this;
}
