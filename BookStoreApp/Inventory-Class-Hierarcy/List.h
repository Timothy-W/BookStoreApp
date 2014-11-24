

#ifndef Inventory_H
#define Inventory_H


#include <iostream>
using namespace std;

class Inventory{

public:

   Inventory();
   virtual ~Inventory();
   void BuildInventory();
   void DisplayInventory();
   void SetInventoryName();
   string GetInventoryName();
   void SetDatabasePath();
   string GetDatabasePath();

private:
   string InventoryName;
   string DatabasePath;
};

#endif