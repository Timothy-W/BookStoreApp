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
    
   
   return 0;
   
}



