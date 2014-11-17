#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

#include "InventoryItem.h"

using namespace std;

class Product : public InventoryItem //derived from InventoryItem class 
{
protected:
   int ProductID; //never passed always generated
   double Price;

public:
   //Constructor
   Product::Product() : InventoryItem(), ProductID(SetID()), Price(0.0) {}
   Product::Product(string Name, int Quantity, double Price) : 
      InventoryItem(Name, Quantity) { SetPrice(Price); SetID(); }

   //Destructor
   virtual ~Product() {}

   //Accessors
   int GetID() { return ProductID; }
   double GetPrice() { return Price; }

   //Mutators
   bool SetID();
   bool SetPrice(double Price);

   //Class member funtions
   virtual const void DisplayItem();
   int generateProductID();

   virtual const bool MoreValuable(const Item & ItemObject);
};

#endif