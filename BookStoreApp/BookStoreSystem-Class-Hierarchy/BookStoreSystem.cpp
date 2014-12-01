 /*
   Main entry point for the app
*/

#include <iostream>
#include <cctype>
#include "BookStoreSystem.h"


BookStoreSystem::BookStoreSystem()
{
    inventory = new InventoryList("Inventory List", "../BookStoreApp/databases/book-inventory.txt");
    employeeListing = new EmployeeList("Employee List", "../BookStoreApp/databases/employee-list.txt");
}

BookStoreSystem::BookStoreSystem(std::string storeName, std::string storeAddress) : storeName(storeName), storeAddress(storeAddress)
{}

//BookStoreSystem(string storeName, string storeAddress, string invPATH, string empPATH, string tranPATH){}

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
  //  cin.ignore(1000, '\n');
  //  cin.clear();
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
    cin >> choice;
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
        modifyEmployees();
        break;
    case 5:
        modifyTransactions();
        break;
    case 6:
        modifyInventory();
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
void BookStoreSystem::showTransactions() const
{
    for (int i = 0; i < transactionsList->GetListCount(); i++)
        cout << transactionsList->GetElementAtPosI(i);
}
void BookStoreSystem::showEmployees() const
{
    for (int i = 0; i < employeeListing->GetListCount(); i++)
        cout << employeeListing->GetElementAtPosI(i);
}

// Below methods modify the vectors

void BookStoreSystem::modifyInventory()
{
    int targetProdID=0;
    int choice=0;
    Item * targetItem;

    targetItem = inventory->SearchID(targetProdID);

}
void BookStoreSystem::addItem()
{}
void BookStoreSystem::removeItem(Item * targetItem)
{}
void BookStoreSystem::editItem(Item * targetItem){}
void BookStoreSystem::searchInventory() const
{
}


void BookStoreSystem::modifyTransactions(){}
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
void BookStoreSystem::removeTransaction(Transaction * targetTransaction)
{}
void BookStoreSystem::editTransaction(Transaction * targetTransaction)
{}



void BookStoreSystem::modifyEmployees()
{
    int targetPersonID;
    int choice;
    Person * targetPerson = NULL;

    cout << "1) Edit Person"
        << "2) Add Person"
        << "3) Remove Person" << endl;

    cout << "\nEnter Employee ID:" << endl;
    cin >> targetPersonID;

    if (employeeListing->Search(targetPersonID) != 0)         //If person exists
        targetPerson = employeeListing->Search(targetPersonID);
    else if (targetPersonID == 0)
        ;//user intends to add
    else
    {
        cout << "\nPerson not found in database";
    }
    
    cin >> choice;
    switch (choice)
    {
    case 1: 
        editEmployee(targetPerson);
        break;
    case 2:
        addEmployee();
        break;
    case 3:
        removeEmployee(targetPerson);
        break;
    default:
        cout << "Invalid selection";
        break;
    }

}
void BookStoreSystem::addEmployee()
{
    char yesNo;
    bool isManager = false;
    managerType managerlvl;
    int managerlvlInt;
    int age;
    string name;
    string address;

    cout << "A manager? Y/N";
    cin >> yesNo;
    if (toupper(yesNo) == 'Y')
        isManager = true;
    cin >> age;
    getline(cin, name);
    getline(cin, address);

    if (isManager)
    {
        cout << "\n0 shift_manager \n1 store_manager \n2VP\n3CEO";
        cin >> managerlvlInt;
        if (managerlvlInt > 3 || managerlvlInt < 0)
        {
            cout << "Invalid #" << endl;
            return;
        }
        managerlvl = (managerType)managerlvlInt;
        Manager * newGuy = new Manager(age, address, name, managerlvl);
    }

    Employee * newGuy = new Employee(age, address, name);
    employeeListing->AddToList(newGuy);

}
void BookStoreSystem::removeEmployee(Person * targetPerson)
{
    if (targetPerson != NULL) //person found
        employeeListing->RemoveFromList(targetPerson);
    else
        cout << "\nPerson not found\n";
}
void BookStoreSystem::editEmployee(Person * Employee)
{
//May be complicated 
}


void BookStoreSystem::adjustSalePrice()
{
    
}