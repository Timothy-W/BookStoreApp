 /*
   Main entry point for the app
*/

#include <iostream>

using namespace std;

#include "BookStoreSystem.h"

BookStoreSystem::BookStoreSystem()
{

}

BookStoreSystem::~BookStoreSystem()
{
}

bool BookStoreSystem::login(InventoryList * employeeList) 
{
    string loginName;
    int loginPIN;

    cout << "\nPlease enter name";
    cin >> loginName;
    cout << "\nEnter I.D.";
    cin >> loginPIN;
    
}

void BookStoreSystem::makeOrder()
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
{}

void BookStoreSystem::showInventory() const
{}

void BookStoreSystem::showTransactions() const
{}

void BookStoreSystem::adjustSalePrice()
{}