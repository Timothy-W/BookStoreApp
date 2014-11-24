#include "InventoryItem.h"

const void InventoryItem::DisplayItem()
{
   cout << Name << " " << Quantity << " " << endl;
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