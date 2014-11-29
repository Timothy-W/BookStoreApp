#include "Manager.h"
#include "Item-Class-Hierarchy\Item.h"


Manager::Manager() : managerLevel((managerType)0)
{
}

Manager::Manager(int age, string address, string name, managerType level) : Employee(age, address, name), managerLevel(level)
{
}

Manager::~Manager()
{
}

void Manager::setLevel(managerType level)
{ 
    managerLevel = level;
}

Manager::managerType Manager::getLevel() const
{
    return managerLevel;
}

// FIX WHEN MANAGER TYPES ARE DECIDED
string Manager::getLevelString() const
{
    string managerStr[] = { "shift_manager", "store_manager", "VP", "CEO" };
    return managerStr[(int)managerLevel];
}

void Manager::editItem(Item &item)
{
  //  cout << "Enter item ID" item, ID, quantity
}

ostream& operator<<(ostream& os, const Manager& man)
{
    os << "\nName: " << man.name << "\nAddress: " << man.address << "\nEmployee ID #: " << man.employeeID << "\nManager Level: " << man.getLevelString();
    return os;
}
