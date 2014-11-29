 /*
   Main entry point for the app
*/

#include <iostream>
using namespace std;
#include "Inventory-Class-Hierarcy\\List.h"
#include "Inventory-Class-Hierarcy\\InventoryList.h"
#include "Item-Class-Hierarchy\\Item.h"
#include "Transaction-Class-hierarchy\StoreOrder.h"


int main()
{
   /*
   // Template List class tests with int
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
   InventoryList * invList = new InventoryList("Book Inventory", "/Users/Captain/Documents/xcode-workspace/CS2B/Assignment_3/Assignment_3/inventory.txt");
   invList->BuildFromDatabase();

   InventoryList * employeeList = new InventoryList("Employee List", "C:\text.txt");
   employeeList->BuildFromDatabase();

   InventoryList * transactionList = new InventoryList("TransactionsList", "PATH");
   transactionList->BuildFromDatabase();
   
   login(employeeList);

   delete invList;

   return 0;
   
}

bool login(InventoryList * employeeList)
{
    string loginName;
    int loginPIN;

    cout << "\nPlease enter name";
    cin >> loginName;
    cout << "\nEnter I.D.";
    cin >> loginPIN;

    
}

void makeOrder(InventoryList *transactionList)
{
    int PID;
    int TID;
    int quantity;
    
    cout << "Enter Product I.D.";
    cin >> PID;
    cout << "Enter Transaction I.D.";
    cin >> TID;
    cout << "Enter quantity";
    cin >> quantity;
    
    
    transactionList->AddToList();
}

void menu()
{
    int choice;
    cout << "\n1) Display employees\n 2) Display Transactions\n3) Display Inventory\n4)Make order\n5) Edit Item \n ";
    
    switch (choice)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 'q':
        break;
    default:
        break;
    }
}

void makeOrderForStore(InventoryList *transactionList)

