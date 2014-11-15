#ifndef PRODUCT_H
#define PRODUCT_H

#include "InventoryItem.h"
class Product :
   public InventoryItem
{
public:
   Product();
   virtual ~Product();
   virtual int DisplayItem();
protected:
   int ProductID;
};

#endif