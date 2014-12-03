 /*
   Main entry point for the app
*/

#include <iostream>
#include <map>
using namespace std;

#include "Inventory-Class-Hierarcy\\List.h"
#include "Inventory-Class-Hierarcy\\InventoryList.h"
#include "Item-Class-Hierarchy\\Item.h"
#include "Transaction-Class-hierarchy\StoreOrder.h"
#include "BookStoreSystem-Class-Hierarchy\BookStoreSystem.h"


int main()
{
    BookStoreSystem * OurBookStore = new BookStoreSystem("Our Awesome Book Store", "1234 El Monte dr.", "C:\\Users\\Hassu_2\\BookStoreApp\\BookStoreApp\\databases\\book-inventory.txt", "C:\\Users\\Hassu_2\\BookStoreApp\\BookStoreApp\\databases\\employee-list.txt", "transactions path");
    while (true)
        OurBookStore->menu();
    
    
    
    /*map<string,string> databases;

   databases["Book-Inventory"] = "/Users/Captain/GitHub/BookStoreApp/BookStoreApp/databases/book-inventory.txt";


   Item *testItem = new PaperBook("Paper Book", 300, 3.99,
                                  12345, "test", "test", HORROR,
                                  "Test", 789);

   //test test test - tim

   // Template List class tests with int
   
   // Template List class tests with int
   int length = 10;
   int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   List<int> myList("My List", arr, length);
   cout << "count is " << myList.GetListCount() << endl;
   myList.DisplayList();
   myList.RemoveFromList( 6 );
   myList.DisplayList();
   cout << "count is " << myList.GetListCount() << endl;
   

   // Template List class test with an Item List
<<<<<<< HEAD
   InventoryList * invList = new InventoryList("Book Inventory", "/Users/Captain/Documents/xcode-workspace/CS2B/Assignment_3/Assignment_3/inventory.txt");
   invList->BuildFromDatabase();
=======
   InventoryList *invList = new InventoryList( "Book Inventory", databases["Book-Inventory"] );
   //invList->BuildFromDatabase();
>>>>>>> e8dfb858b4fd112020f46c658265d50fdbba59d9

   InventoryList * employeeList = new InventoryList("Employee List", "C:\text.txt");
   employeeList->BuildFromDatabase();

   InventoryList * transactionList = new InventoryList("TransactionsList", "PATH");
   transactionList->BuildFromDatabase();
   
   login(employeeList);

   delete invList;
   */
   return 0;
   
}



