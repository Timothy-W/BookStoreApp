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

