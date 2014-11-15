#pragma once
#include "InventoryItem.h"
class Product :
   public InventoryItem
{
public:
   Product();
   virtual ~Product();
   virtual int DisplayItem();
};

