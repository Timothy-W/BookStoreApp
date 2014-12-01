#include "../Inventory-Class-Hierarcy/EmployeeList.h"
#include "../Inventory-Class-Hierarcy/List.h"
#include "../Item-Class-Hierarchy/Item.h"
#include "../Transaction-Class-hierarchy/StoreOrder.h"
#include "../Inventory-Class-Hierarcy/InventoryList.h"

class BookStoreSystem
{
public:
    BookStoreSystem();
    BookStoreSystem(string storeName, string storeAddress);
    ~BookStoreSystem();

protected:
    InventoryList * inventory;
    EmployeeList  * employeeListing;
    InventoryList * transactionsList; //RENAME TO TransactionList * ....

public:
    void menu();
    bool login();
    void makeOrder();
    void searchInventory() const;

private:
    void adjustSalePrice();

    void showInventory() const;
    void showTransactions() const;
    void showEmployees() const;

    void editInventory();       //add, subtract, edit an Item
    void addItem();             //add item
    void removeItem();          //subtract Item
    void editItem();             //edit Item properties

    void editTransactions();    //add, subtract, edit a Transaction
    void addTransaction();
    void removeTransaction();
    void editTransaction();

    void editEmployees();       //add, subtract, edit an Employee
    void addEmployee();             
    void removeEmployee();
    void editEmployee();
};
