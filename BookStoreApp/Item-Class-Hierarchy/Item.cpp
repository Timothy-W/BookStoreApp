#include "Item.h"

using namespace std;


Item::Item()
{
   //cout << "Item Constructor" << endl;
}


/*Item* Clone()                 //takes no parameter and returns a pointer to an Item object.Default implementation is to return NULL pointer.
{
   return NULL;
}*/

void const Item::DisplayItem()             //take no parameter and return nothing.Default implementation is to display an empty string(“”).
{
   cout << "" << endl;
}