 /*
   Main entry point for the app
*/

#include <iostream>
#include <map>
#include "BookStoreSystem-Class-Hierarchy\BookStoreSystem.h"
#include "Inventory-Class-Hierarcy\InventoryList.h"
#include "Item-Class-Hierarchy\Item.h"
#include "Transaction-Class-hierarchy\StoreOrder.h"

using namespace std;

//#include "List.h"
//#include "InventoryList.h"
//#include "Item.h"
//#include "StoreOrder.h"
//#include "BookStoreSystem.h"


void welcomeMessage();
int main()
{
    
   map<string,string> databases;
   databases["Book-Inventory"] = "C:/Users/Hassu_2/BookStoreApp/BookStoreApp/databases/book-inventory.txt";
   databases["Employee-List"] = "C:/Users/Hassu_2/BookStoreApp/BookStoreApp/databases/employee-list.txt";

   
   welcomeMessage();
   BookStoreSystem * OurBookStore = new BookStoreSystem("Our Awesome Book Store", "1234 El Monte dr.", databases["Book-Inventory"], databases["Employee-List"], "transactions path");
   OurBookStore->menu();


   return 0; 
}

void welcomeMessage()
{
    cout << "\nWelcome\n";
}

