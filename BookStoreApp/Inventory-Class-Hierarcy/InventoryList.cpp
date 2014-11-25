



#include "InventoryList.h"

InventoryList::InventoryList(): List(), DatabasePath(""){}






InventoryList::InventoryList( string name, string databasePath):
   List(name), DatabasePath(databasePath){}






InventoryList::InventoryList( string name, Item* array[], int arrayLength, string databasePath):
   List( name, array, arrayLength), DatabasePath(databasePath){}





InventoryList::~InventoryList()
{

   cout << "\nInventory List " << ListName << " Destroyed\n";

}





void InventoryList::BuildFromDatabase()
{

   if( DatabasePath != "" )
   {

      ifstream inventoryFile(DatabasePath);

      if ( !inventoryFile ) {
         cerr << "ERROR: Failed to open input file\n";
         exit(-1);
      }

      inventoryFile.close();

   }
   else
   {

      cout << "\nDatabase Path not set\n";

   }
   
}