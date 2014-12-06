#include "Manager.h"
#include "Item.h"
#include "StoreOrder.h"
#include "EmployeeList.h"
#include "InventoryList.h"

#include "Order.h"

#include "OrderList.h"

#include "OrderList.h"

#include "Order.h"
#include <string>
#include <iostream>
using namespace std;

class BookStoreSystem
{
public:

    // 3 constructors
    BookStoreSystem();
    BookStoreSystem(string storeName, string storeAddress);
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
    void initLists();
    void initLists(string invPATH, string empPATH, string tranPATH);

    //These display the 3 main vectors
    void showInventory() const;
    void showTransactions() const;
    void showEmployees() const;


    //INVENTORYLIST   interaction
    void modifyInventory();       //add, subtract, edit an Item
    void addItem();             //add item
    void removeItem(Item * targetItem);          //subtract Item
    void searchInventory() const;

    //TRANSACTIONLIST interaction
    void modifyTransactions();    //add, subtract, edit a Transaction
    void addTransaction();
    void removeTransaction(Order<Item *> * targetTransaction);
    void removeTransaction(StoreOrder * targetTransaction);
    void removeTransaction(StoreOrder * targetTransaction);
    void removeTransaction(Order<Item *> * targetTransaction);
    void viewTransaction();

    //EMPLOYEELIST    interaction
    void modifyEmployees();       //add, subtract, edit an Employee
    void addEmployee();             
    void removeEmployee(Person * targetPerson);
    void viewEmployee(Person * employee);
    
    //Time did not permit
<<<<<<< HEAD
<<<<<<< HEAD
		/*void editItem(Item * targetItem);            
		void editTransaction(Order<Item *> * targetTransaction);
		void editEmployee(Person * targetPerson);*/
=======
    void editItem(Item * targetItem);            
    void editTransaction(StoreOrder * targetTransaction);
    void editEmployee(Person * targetPerson);
>>>>>>> 64e8f467b9af6281dc724526d39d034e1cf9be0e
=======
    void editItem(Item * targetItem);            
    void editTransaction(StoreOrder * targetTransaction);
    void editEmployee(Person * targetPerson);
=======
		/*void editItem(Item * targetItem);            
		void editTransaction(Order<Item *> * targetTransaction);
		void editEmployee(Person * targetPerson);*/
>>>>>>> mine
>>>>>>> master

};
