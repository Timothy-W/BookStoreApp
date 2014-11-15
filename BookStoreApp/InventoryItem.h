#pragma once
#include "Item.h"
class InventoryItem :
   public Item
{
public:
   InventoryItem();
   virtual ~InventoryItem();
   virtual void DisplayItem();
};

