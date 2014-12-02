#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H

#include "Item.h"

class InventoryItem : public Item
{
protected:
   string Name;
   int Quantity;

public:
   InventoryItem() : Name(""), Quantity(0) {}
   InventoryItem(string Name, int Quantity) : Name(Name), Quantity(Quantity) {}

   virtual ~InventoryItem() {}

   const string getName() { return Name; }
   const int getQuantity() { return Quantity; }

   void setName(string Name) { this->Name = Name; }
   bool setQuantity(int Quantity);

   virtual const void DisplayItem();
};

#endif