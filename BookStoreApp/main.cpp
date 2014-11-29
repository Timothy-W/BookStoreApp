   

/*
   Main entry point for the app
*/


#include <iostream>
#include <map>
using namespace std;
#include "List.h"
#include "InventoryList.h"
#include "Item.h"

int main()
{
   map<string,string> databases;

   databases["Book-Inventory"] = "/Users/Captain/GitHub/BookStoreApp/BookStoreApp/databases/book-inventory.txt";


   Item *testItem = new PaperBook("Paper Book", 300, 3.99,
                                  12345, "test", "test", HORROR,
                                  "Test", 789);

   //test test test - tim

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
   InventoryList *invList = new InventoryList( "Book Inventory", databases["Book-Inventory"] );
   //invList->BuildFromDatabase();

   delete invList;

   return 0;
   
}