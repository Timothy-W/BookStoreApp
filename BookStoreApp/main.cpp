 /*
   Main entry point for the app
*/

#include <iostream>
#include <map>
using namespace std;

#include "List.h"
#include "InventoryList.h"
#include "Item.h"
#include "StoreOrder.h"
#include "BookStoreSystem.h"


int main()
{


   map<string,string> databases;
   databases["Book-Inventory"] = "/Users/Captain/GitHub/BookStoreApp/BookStoreApp/databases/book-inventory.txt";
   databases["Employee-List"] = "/Users/Captain/GitHub/BookStoreApp/BookStoreApp/databases/employee-list.txt";

   
   BookStoreSystem * OurBookStore = new BookStoreSystem("Our Awesome Book Store", "1234 El Monte dr.", databases["Book-Inventory"], databases["Employee-List"], "transactions path");
   while (true)
      OurBookStore->menu();

    

   return 0;
   
}



