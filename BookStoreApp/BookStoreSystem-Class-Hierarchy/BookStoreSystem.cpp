 /*
   Main entry point for the app
*/

#include <iostream>
#include <cctype>
#include "BookStoreSystem.h"


BookStoreSystem::BookStoreSystem()
{
    inventory = new InventoryList("Inventory List", "/Users/Captain/GitHub/BookStoreApp/BookStoreApp/databases/book-inventory.txt");
    employeeListing = new EmployeeList("Employee List", "/Users/Captain/GitHub/BookStoreApp/BookStoreApp/databases/employee-list.txt");
}

BookStoreSystem::BookStoreSystem(string storeName, string storeAddress ) : storeName(storeName), storeAddress(storeAddress)
{
    initLists();
}

BookStoreSystem::BookStoreSystem(string storeName, string storeAddress, string invPATH, string empPATH, string tranPATH) : storeName(storeName), storeAddress(storeAddress), invPATH(invPATH), empPATH(empPATH), tranPATH(tranPATH)
{
    initLists(invPATH, empPATH, tranPATH);
}

BookStoreSystem::~BookStoreSystem()
{
    delete inventory;
    delete employeeListing;
    delete transactionsList;
}


//done
void BookStoreSystem::initLists()
{
    inventory = new InventoryList("Inventory List", "/Users/Captain/GitHub/BookStoreApp/BookStoreApp/databases/book-inventory.txt");
    employeeListing = new EmployeeList("Employee List", "/Users/Captain/GitHub/BookStoreApp/BookStoreApp/databases/employee-list.txt");
    //transactionsList = new InventoryList("Transaction List", "../BookStoreApp/databases/employee-list.txt");
}
void BookStoreSystem::initLists(string invPATH, string empPATH, string tranPATH)
{
    inventory = new InventoryList("Inventory List", invPATH);
    employeeListing = new EmployeeList("Employee List", empPATH);
    //transactionsList = new InventoryList("Transaction List", tranPATH);
}

//done
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
            {
                user = employeeListing->GetElementAtPosI(i);
                nameMatches = true; // that said employee's name matches the user's input for login name
            }
        }
    }

    return(pinFound && nameMatches); //if both are true, returns true
}

void BookStoreSystem::menu()
{
    int choice; 
    bool menuIsRunning = true;
    while (menuIsRunning)
    {
        cout << "\n1) Display Employees\n"
            << "2) Display Transactions\n"
            << "3) Display Inventory\n\n"
            << "4) Edit Employees\n"             //using Employee I.D.
            << "5) Edit Transactions \n"        //using Transaction I.D.
            << "6) Edit Inventory\n"             //using product I.D.
            << "7) Search Inventory\n"
            << "(q to quit)\n"
            << "Select an option: " << endl;
        cin >> choice;
        switch (choice)
        {
            case 1:
                showEmployees();            //DONE
                break;
            case 2:
                showTransactions();         
                break;
            case 3:
                showInventory();           //DONE
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
        cin.ignore(1000, '\n');
        cin.clear();
    }
}

// three below are done
void BookStoreSystem::showInventory() const
{
   inventory->DisplayList();
}
void BookStoreSystem::showTransactions() const
{
   transactionsList->DisplayList();
}
void BookStoreSystem::showEmployees() const
{
   employeeListing->DisplayList();
}

// Below methods modify the vectors
void BookStoreSystem::modifyInventory() 
{
    int targetProdID=0;
    int choice=0;
    Item * targetItem = NULL;

    cout << "1) Edit Item\n"
        << "2) Add Item\n"
        << "3) Remove Item\n" 
        << "4) View Item\n"    << endl;
    cin >> choice;
    if (choice == 2)
    {
        addItem();
        return;
    }

    cout << "\nEnter product ID:" << endl;
    cin >> targetProdID;
    if (employeeListing->Search(targetProdID) != 0)         //If Item exists
        targetItem = inventory->SearchID(targetProdID);
    else
    {
        cout << "\nItem not found in database";
        return;
    }

    
    switch (choice)
    {
    case 1:
        editItem(targetItem);
        break;
    case 3:
        removeItem(targetItem);
        break;
    case 4:
        cout << targetItem;
    default:
        cout << "Invalid selection";
        break;
    }
} 
void BookStoreSystem::addItem()
{

    int quantity;
    int pageCount;
    int ISBN;
    int itemType;
    int genreInt;
    int eFileInt;
    int audioFileInt;
    int numPages;
    double price;
    string author;
    string bookType="" ;
    string title;
    string publisher;
    string name;
    genreType genre;
    audioFileFormat audioFileFormat;
    eBookFileFormat eFileFormat;
    Item * newItem = NULL;

    cout << "\n1.)eBook\n2.)Audio Book\n3.)Paper Book" << endl;
    cin >> itemType;
    if (itemType == 1)
        bookType = "eBook";
    else if (itemType == 2)
        bookType = "Audio Book";
    else if (itemType == 3)
        bookType = "Paper Book";
    else
    {
        cout << "invalid selection";
        return;
    }

    cout << "\nBook quantity?\n";
    cin >> quantity;

    cout << "\nBook price?\n";
    cin >> price;

    cout << "\nBook isbn?\n";
    cin >> ISBN;
    cin.ignore();

    cout << "\nBook author?\n";
    getline(cin, author);
    cout << "\nBook title?\n?";
    getline(cin, title);
    cout << "\nBook genre?\n?"
        << "0 Unknown\n 1 Science fiction\n 2 Mystery\n 3 Horror\n 4 Romance"   ;
    cin >> genreInt;
    genre = (genreType)genreInt;
    cin.ignore();
    cout << "\nBook publisher?\n?";
    getline(cin, publisher);

    if (itemType == 1)
    {
        cout << "Which eBook file format?\n"
            << "1 Unknown/Other \n2 PDF \n3 EPUB\n";
        cin >> eFileInt;
        eFileFormat = (eBookFileFormat)eFileInt;
        newItem = new eBook(bookType, quantity, price, ISBN, author, title, genre, publisher, eFileFormat);
    }
    else if (itemType == 2)
    {
        string YesOrNo;
        cout << "\nIs this Audio Book an mp3 Y/N ?\n";
        cin >> YesOrNo;
        if (toupper(YesOrNo[0]) == 'Y')
           audioFileFormat = MP3;
        else
            audioFileFormat = UNKNOWN_AUDIO;
        newItem = new AudioBook(bookType, quantity, price, ISBN, author, title, genre, publisher, audioFileFormat);
    }  
    else
    {
        cout << "\n How many pages in your stupid book??\n";
        cin >> numPages;
        newItem = new PaperBook(bookType, quantity, price, ISBN, author, title, genre, publisher, numPages);
    }
    inventory->AddToList(newItem);
} 
void BookStoreSystem::removeItem(Item * targetItem)
{
    inventory->RemoveFromList(targetItem);
} 
void BookStoreSystem::editItem(Item * targetItem){} 
void BookStoreSystem::searchInventory() const
{
    string input;
    cout << "Search for Book either by ISBN, title, or author";
    getline(cin, input);

    //check if input is a number
    string::const_iterator iter = input.begin();
    while (iter != input.end() && isdigit(*iter))
        iter++;
    //user intends to search by isbn
    if ( iter == input.end())
    {
        inventory->Search(atoi(input.c_str()));
    }
    //user intends to search by title/author
    else
    {
        inventory->Search(input);
    }
} 

//These 4  are untouched
void BookStoreSystem::modifyTransactions(){}
void BookStoreSystem::addTransaction()
{   
 //   transactionsList->AddToList();
}
void BookStoreSystem::removeTransaction(Transaction * targetTransaction)
{
    //transactionsList->RemoveFromList(targetTransaction);
}
void BookStoreSystem::editTransaction(Transaction * targetTransaction)
{}



void BookStoreSystem::modifyEmployees()
{
    int targetPersonID;
    int choice;
    Person * targetPerson = NULL;

    cout << "1) Edit Person\n"
         << "2) Add Person\n"
         << "3) Remove Person\n"
            "4) View Person\n" << endl;
    cin >> choice;

    if (choice == 2)
    {
        addEmployee();
        cin.ignore();
        return;
    }

    cout << "\nEnter Employee ID:" << endl;
    cin >> targetPersonID;

    targetPerson = employeeListing->Search(targetPersonID);
    if (!targetPerson)         //If person does not exist
    {
        cout << "\nPerson not found in database";
        cin.ignore();
        return;
    }
    
    switch (choice)
    {
    case 1: 
        editEmployee(targetPerson);
        break;
    case 4:
        viewEmployee(targetPerson);
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

    cin.ignore();
    cout << "Person's Full name?\n";
    getline(cin, name);
    
    
    cout << "A manager? Y/N\n";
    cin >> yesNo;
    if (toupper(yesNo) == 'Y')
        isManager = true;
    
    cout << "\nPerson's age?\n";
    cin >> age;
    cin.ignore();

    cout << "\nPerson's address?\n";
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
        Manager * newGuy = new Manager(age, address, name, NULL, managerlvl);
    }

    Employee * newGuy = new Employee(age, address, name, NULL);

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
void BookStoreSystem::viewEmployee(Person * targ)
{
    Manager * mg = dynamic_cast<Manager  *>(targ);
    Employee * ep = dynamic_cast<Employee *>(targ);
    Customer * cs = dynamic_cast<Customer *>(targ);

    if (mg)
    {
        cout << "\n" << *mg << "\n";
    }
    else if (ep)
    {
        cout << "\n" << *ep << "\n";
    }
    else if (cs)
    {
        cout << "\n" << *cs << "\n";
    }
}
