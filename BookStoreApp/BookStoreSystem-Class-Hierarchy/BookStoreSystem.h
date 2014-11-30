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
    void adjustSalePrice();
    void searchInventory() const;
    void showInventory() const;
    void showTransactions() const;

};
