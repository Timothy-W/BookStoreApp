#include "Manager.h"
#include "Item.h"
#include "StoreOrder.h"
#include "EmployeeList.h"
#include "InventoryList.h"
#include "OrderList.h"
#include <iostream>
#include <cctype>
#include "StoreOrder.h"

#include "Order.h"
#include <string>
#include <iostream>
using namespace std;

class BookStoreSystem
{
public:

    // 3 constructors
    BookStoreSystem();
    BookStoreSystem(string storeName, string storeAddress, string invPATH, string empPATH, string tranPATH);
    ~BookStoreSystem();

protected:

    InventoryList * inventory;
    EmployeeList  * employeeListing;
    OrderList * transactionsList; //RENAME TO TransactionList * ....
    
    Person * user = NULL;
    string storeName;
    string storeAddress;
    string invPATH;
    string empPATH;
    string tranPATH;
 
public:
    void menu();
    Person * login();
    void makeOrder();

private:
    //Initializes the 3 main vectors
    void initLists(string invPATH, string empPATH, string tranPATH);

    //These display the 3 main vectors
    void showInventory() const;
    void showTransactions() const;
    void showEmployees() const;


    //INVENTORYLIST   interaction
    void modifyInventory();       //add, subtract, edit an Item
    void addItem();             //add item
    void removeItem(Item * targetItem);          //subtract Item
    Item* searchInventory();

    //TRANSACTIONLIST interaction
    void modifyTransactions();    //add, subtract, edit a Transaction
    void newStoreOrder();
    //void addToExistingInventory(Item* editableItem);
    void removeTransaction(StoreOrder  * targetTransaction);
	void viewTransaction(StoreOrder  * targetTransactionn);

    //EMPLOYEELIST    interaction
    void modifyEmployees();       //add, subtract, edit an Employee
    void addEmployee();             
    void removeEmployee(Person * targetPerson);
    void viewEmployee(Person * employee);
    
    //Time did not permit

		/*void editItem(Item * targetItem);            
		void editTransaction(Order<Item *> * targetTransaction);
		void editEmployee(Person * targetPerson);*/

};
