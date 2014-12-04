#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
using namespace std;


class Item
{
public:
   Item();
   virtual ~Item() {};
   virtual int GetID(){ return -1; };
   //virtual const Item* Clone() = 0;                 //takes no parameter and returns a pointer to an Item object.Default implementation is to return NULL pointer.
   virtual const void DisplayItem() = 0;                //take no parameter and return nothing.Default implementation is to display an empty string(“”).
};

#endif // !ITEM_H
