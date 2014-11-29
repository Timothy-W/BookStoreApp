

#ifndef InventoryList_H
#define InventoryList_H


#include "List.h"
#include "Item.h"
#include "Book.h"
#include "PaperBook.h"
#include "AudioBook.h"
#include "eBook.h"
#include <fstream>


class InventoryList : public List<Item*>{

public:
   InventoryList();
   InventoryList( string name, string databasePath);
   virtual ~InventoryList();

   void BuildFromDatabase();
   void SetDatabasePath();
   string GetDatabasePath();
   Item* Search( string bookProperty );
   Item* Search(int isbn);
   virtual void RemoveFromList( Item* item );

private:
   string DatabasePath;
   void Genre(genreType& bGenre, string identifier);
   void AudioFormat(audioFileFormat& abFormat, string identifier);
   void EbookFormat(eBookFileFormat& ebFormat, string identifier);
};

#endif