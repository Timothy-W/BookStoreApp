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



void BookStoreSystem::menu()
{
    int choice; 
    bool menuIsRunning = true;
    cout << "\n1) Display Employees\n "
        << "2) Display Transactions\n"
        << "3) Display Inventory\n"

        << "4) Edit Employees\n"             //using Employee I.D.
        << "5) Edit Transactions \n "        //using Transaction I.D.
        << "6) Edit Inventory\n"             //using product I.D.
        << "7) Search Inventory\n" << endl;
    
    switch (choice)
    {
    case 1:
        showEmployees();
        break;
    case 2:
        showTransactions();
        break;
    case 3:
        showInventory();
        break;
    case 4:
        editEmployees();
        break;
    case 5:
        editTransactions();
        break;
    case 6:
        editInventory();
        break;
    case 7: 
        searchInventory();
        break;
    case 'q':
    case 'Q':
        menuIsRunning = false;
        break;
    default:
        break;
    }
}





void BookStoreSystem::showInventory() const
{
    for (int i = 0; i < inventory->GetListCount(); i++)
        cout << inventory->GetElementAtPosI(i);
}
void BookStoreSystem::editInventory()
{}
void BookStoreSystem::addItem()
{}
void BookStoreSystem::removeItem()
{}
void BookStoreSystem::searchInventory() const
{
}



void BookStoreSystem::showTransactions() const
{
    for (int i = 0; i < transactionsList->GetListCount(); i++)
        cout << transactionsList->GetElementAtPosI(i);
}
void BookStoreSystem::editTransaction()
{}
void BookStoreSystem::addTransaction()
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
    
    
 //   transactionsList->AddToList();
}
void BookStoreSystem::removeTransaction()
{}



void BookStoreSystem::showEmployees() const
{
    for (int i = 0; i < employeeListing->GetListCount(); i++)
    {
        cout << "\n" << i << "\n" << employeeListing->GetElementAtPosI(i);
    }
}
void BookStoreSystem::editEmployees()
{
    int targetEmployeeID;
    int choice;

    Person * targetEmployee;
    cout << "\nEnter Employee ID:" << endl;
    cin >> targetEmployeeID;

    if (employeeListing->Search(targetEmployeeID) != 0)         //If person exists
        targetEmployee = employeeListing->Search(targetEmployeeID);
    else
    {
        cout << "\nPerson not found in database";
        return;
    }
    
    cout << "1) Edit Person"
        << "2) Add Person"
        << "3) Remove Person" << endl;

    switch (choice)
    {
    case 1: 
        break;
    case 2:
        break;
    case 3:
        break;

    default:
        cout << "Invalid selection";
        break;
    }

}
void BookStoreSystem::addEmployee(){}
void BookStoreSystem::removeEmployee(){}
void BookStoreSystem::editEmployee(){}

void BookStoreSystem::adjustSalePrice()
{
    
}