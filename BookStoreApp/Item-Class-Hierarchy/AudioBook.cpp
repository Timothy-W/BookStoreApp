#include "AudioBook.h"


bool AudioBook::setAudioFormat(audioFileFormat fileFormat)
{
   this->fileFormat = fileFormat;
   return true;
}

const void AudioBook::DisplayItem()
{
   Book::DisplayItem();
}

ostream& operator<<(ostream& os, const AudioBook& ep){
   os << ep.Name << ";" << ep.Quantity << ";" << ep.Price << ";" << ep.ISBN << ";" << ep.author << ";" <<
      ep.title << ";" << ep.genre << ";" << ep.publisher << ";" << ep.fileFormat << endl;
   return os;
}

