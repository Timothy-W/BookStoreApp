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

void welcomeMessage();
int main()
{

	map<string, string> databases;
	databases["Book-Inventory"] = "C:/Users/hh/github/BookStoreApp/BookStoreApp/databases/book-inventory.txt";
	databases["Employee-List"] = "C:/Users/hh/github/BookStoreApp/BookStoreApp/databases/employee-list.txt";
	databases["Order-List"] = "C:/Users/hh/gitHub/BookStoreApp/BookStoreApp/databases/orders.txt";

   //map<string,string> databases;
   //databases["Book-Inventory"] = "/Users/Captain/GitHub/BookStoreApp/BookStoreApp/databases/book-inventory.txt";
   //databases["Employee-List"] = "/Users/Captain/GitHub/BookStoreApp/BookStoreApp/databases/employee-list.txt";
   //databases["Order-List"] = "/Users/Captain/GitHub/BookStoreApp/BookStoreApp/databases/orders.txt";

   
   welcomeMessage();
   BookStoreSystem * OurBookStore = new BookStoreSystem("Our Awesome Book Store", "1234 El Monte dr.", databases["Book-Inventory"], databases["Employee-List"], databases["Order-List"]);
   OurBookStore->menu();
   cout << "exitted";
   cin.ignore();

   //OrderList Tests
   /*InventoryList* inventory = new InventoryList("Inventory List", databases["Book-Inventory"]);
   EmployeeList* employeeListing = new EmployeeList("Employee List", databases["Employee-List"]);
   OrderList* transactionsList = new OrderList("Transaction List", databases["Order-List"], employeeListing, inventory);

   transactionsList->DisplayList();*/


   return 0;
}

void welcomeMessage()
{
    cout << "\nWelcome\n";
}

