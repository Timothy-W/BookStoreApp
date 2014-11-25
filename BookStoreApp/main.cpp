   

/*
   Main entry point for the app
*/


#include <iostream>
using namespace std;
#include "Inventory-Class-Hierarcy\\List.h"
#include "Inventory-Class-Hierarcy\\InventoryList.h"
#include "Item-Class-Hierarchy\\Item.h"

int main()
{

   // Template List class tests with int
   /*
   int length = 10;
   int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   List<int> myList("My List", arr, length);
   cout << "count is " << myList.GetListCount() << endl;
   myList.DisplayList();
   myList.RemoveFromList( 6 );
   myList.DisplayList();
   cout << "count is " << myList.GetListCount() << endl;
   */

   // Template List class test with an Item List
   InventoryList *invList = new InventoryList("Book Inventory", "/Users/Captain/Documents/xcode-workspace/CS2B/Assignment_3/Assignment_3/inventory.txt");
   invList->BuildFromDatabase();

   delete invList;

   return 0;
   
}