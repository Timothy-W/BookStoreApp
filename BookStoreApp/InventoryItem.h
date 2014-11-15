#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H

#include "Item.h"
class InventoryItem :
   public Item
{
public:
   InventoryItem();
   virtual ~InventoryItem();
   virtual void DisplayItem();
protected:
   string Name;
   int Quantity;
};

#endif