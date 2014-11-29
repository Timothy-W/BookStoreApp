#include "../Inventory-Class-Hierarcy/EmployeeList.h"
#include "../Inventory-Class-Hierarcy/List.h"
#include "../Inventory-Class-Hierarcy/InventoryList.h"
#include "../Item-Class-Hierarchy/Item.h"
#include "../Transaction-Class-hierarchy/StoreOrder.h"


class BookStoreSystem
{
public:
    BookStoreSystem();
    BookStoreSystem(string storeName, string storeAddress);
    ~BookStoreSystem();

protected:
    InventoryList * inventory;
    EmployeeList  * employeeListing;
    TransactionList * transactions;

public:
    void menu();
    bool login(InventoryList * employeeList);
    void makeOrder();
    void adjustSalePrice();
    void searchInventory() const;
    void showInventory() const;
    void showTransactions() const;

};
