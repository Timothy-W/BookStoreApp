

#ifndef InventoryList_H
#define InventoryList_H


#include "List.h"
#include "Item-Class-Hierarchy\\Item.h"
#include <fstream>

class InventoryList : public List<Item*>{

public:
   InventoryList();
   InventoryList( string name, string databasePath);
   InventoryList( string name, Item* array[], int arrayLength, string databasePath);
   virtual ~InventoryList();

   void BuildFromDatabase();
   void SetDatabasePath();
   string GetDatabasePath();

private:
   string DatabasePath;
};

#endif