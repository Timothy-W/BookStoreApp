#include "Product.h"

using namespace std;

//Product member function definitions------------------------------------------
//Constructors defined in Class
bool Product::SetID()
{
   ProductID = generateProductID();
   return true;
}

bool Product::SetPrice(double Price)
{
   if (Price >= 0.00)
   {
      this->Price = Price;
      return true;
   }
   else
      return false;
}

const void Product::DisplayItem()
{
   InventoryItem::DisplayItem();
   cout << ProductID << " " << fixed << setprecision(2) << Price;
}

int Product::generateProductID()
{
   int id;
   srand(time(NULL) + rand()); // generate a seed
   id = rand() % 100000;             // generate a number between 0-99999
   return id;
}