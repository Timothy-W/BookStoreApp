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

   //map<string, string> databases;
   //databases["Book-Inventory"] = "C:\\Important Documents\\School\\CS 2B\\Projects\\BookStoreApp\\BookStoreApp\\databases\\book-inventory.txt";
   //databases["Employee-List"] = "C:\\Important Documents\\School\\CS 2B\\Projects\\BookStoreApp\\BookStoreApp\\databases\\employee-list.txt";
   //databases["Order-List"] = "C:\\Important Documents\\School\\CS 2B\\Projects\\BookStoreApp\\BookStoreApp\\databases\\orders.txt";

   //Sid's files
   //map<string, string> databases;
   //databases["Book-Inventory"] = "C:\\Users\\Owner\\Documents\\Foothill\\CS 2B\\BookStoreApp\\BookStoreApp\\databases\\book-inventory.txt";
   //databases["Employee-List"] = "C:\\Users\\Owner\\Documents\\Foothill\\CS 2B\\BookStoreApp\\BookStoreApp\\databases\\employee-list.txt";
   //databases["Order-List"] = "C:\\Users\\Owner\\Documents\\Foothill\\CS 2B\\BookStoreApp\\BookStoreApp\\databases\\orders.txt";
   
   welcomeMessage();
   BookStoreSystem * OurBookStore = NULL;
   try{
      OurBookStore = new BookStoreSystem("Our Awesome Book Store", "1234 El Monte dr.", databases["Book-Inventory"], databases["Employee-List"], databases["Order-List"]);
      OurBookStore->menu();
   }catch(string e){

      cout << "\nThere was an error in the system with:\n"
           << e << "\n\n";
      
   }

   if(OurBookStore)
      delete OurBookStore;



   return 0;
}

void welcomeMessage()
{
    cout << "\nWelcome to our Book Store\n";
}

