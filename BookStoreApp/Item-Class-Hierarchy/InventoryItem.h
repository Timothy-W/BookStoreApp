#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H

#include "Item.h"

class InventoryItem : public Item
{
protected:
   string ItemType;
   int Quantity;

public:
   InventoryItem() : ItemType(""), Quantity(0) {}
   InventoryItem(string Name, int Quantity) : ItemType(Name), Quantity(Quantity) {}

   virtual ~InventoryItem() {}

   const string getName() { return ItemType; }
   const int getQuantity() { return Quantity; }

   void setName(string Name) { this->ItemType = Name; }
   bool setQuantity(int Quantity);

   virtual const void DisplayItem();
};

#endif