#pragma once

#include "List.h"
#include "../Item-Class-Hierarchy/Item.h"
#include "../Item-Class-Hierarchy/Book.h"
#include "../Item-Class-Hierarchy/PaperBook.h"
#include "../Item-Class-Hierarchy/AudioBook.h"
#include "../Item-Class-Hierarchy/eBook.h"
#include <fstream>
#include <string>

class InventoryList : public List<Item*>{

public:
   InventoryList();
   InventoryList( string name, string databasePath);
   virtual ~InventoryList();

   void BuildFromDatabase();
   void SetDatabasePath( string path );
   string GetDatabasePath() const;
   vector<Item*> Search( string bookProperty );
   vector<Item*> Search(int isbn);
   Item * SearchID(int ID);
   virtual void RemoveFromList( Item* item );
   virtual void DisplayList();
   void SaveToTextFile();

private:
   string DatabasePath;
   void Genre(genreType& bGenre, string identifier);
   void AudioFormat(audioFileFormat& abFormat, string identifier);
   void EbookFormat(eBookFileFormat& ebFormat, string identifier);
};
