#include "InventoryItem.h"

const void InventoryItem::DisplayItem()
{
   Item::DisplayItem();
   cout << ItemType << " " << Quantity << " ";
}

bool InventoryItem::setQuantity(int Quantity)
{
   if (Quantity >= 0 && Quantity < 2147483647)
   {
      this->Quantity = Quantity;
      return true;
   }
   else
      return false; 
}