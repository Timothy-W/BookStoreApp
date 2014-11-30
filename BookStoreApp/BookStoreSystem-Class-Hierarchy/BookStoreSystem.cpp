 /*
   Main entry point for the app
*/

#include <iostream>

using namespace std;

#include "BookStoreSystem.h"

BookStoreSystem::BookStoreSystem()
{
    inventory = new InventoryList("Inventory List", "../BookStoreApp/databases/book-inventory.txt");
    employeeListing = new EmployeeList("Employee List", "../BookStoreApp/databases/employee-list.txt");
}

BookStoreSystem::~BookStoreSystem()
{
}

bool BookStoreSystem::login() 
{
    string loginName;
    int loginPIN;
    bool pinFound = false;
    bool nameMatches = false;

    cout << "\nPlease enter name:\n";
    cin >> loginName;
    cout << "\nEnter I.D.:\n";
    cin >> loginPIN;
    for (int i = 0; i < employeeListing->GetListCount(); i++)
    {
        if (loginPIN == employeeListing->GetElementAtPosI(i)->getID())
        {
            pinFound = true;    //there exists an employee with that PIN
            if (loginName.compare(employeeListing->GetElementAtPosI(i)->getName()) == 0)
                nameMatches = true; // that said employee's name matches the user's input for login name
        }
    }
    cin.ignore(1000, '\n');
    cin.clear();
    return(pinFound && nameMatches); //if both are true, returns true
}

void BookStoreSystem::makeOrder()
{
    int PID; //product
    int TID;
    int quantity;
    
    cout << "Enter Product I.D.";
    cin >> PID;
    cout << "Enter Transaction I.D.";
    cin >> TID;
    cout << "Enter quantity";
    cin >> quantity;
    
    
    transactionsList->AddToList();
}


void BookStoreSystem::menu()
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


void BookStoreSystem::searchInventory() const
{

}

void BookStoreSystem::showInventory() const
{
    for (int i = 0; i < inventory->GetListCount(); i++)
        cout << inventory->GetElementAtPosI(i);
}

void BookStoreSystem::showTransactions() const
{
    for (int i = 0; i < transactionsList->GetListCount(); i++)
        cout << transactionsList->GetElementAtPosI(i);
}

void BookStoreSystem::adjustSalePrice()
{
    
}