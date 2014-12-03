#include "Manager.h"
#include <string>
#include <fstream>


Manager::Manager() : managerLevel((managerType)0)
{
}

Manager::Manager(int age, string address, string name, managerType level) : Employee(age, address, name), managerLevel(level)
{
}

Manager::~Manager() {
    ofstream out("employeeListOut.txt", ios::trunc);
    out << "Manager;" << this->getID()
    << ";" << this->getLevelString()
    << ";" << this->getName()
    << ";" << this->getAge()
    << ";" << this->getAddress()
    << endl;
    out.close();
}

void Manager::setLevel(managerType level)
{ 
    managerLevel = level;
}

managerType Manager::getLevel() const
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
