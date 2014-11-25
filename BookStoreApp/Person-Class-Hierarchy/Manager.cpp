#include "Manager.h"

Manager::Manager() : managerLevel((managerType)0)
{
}

Manager::Manager(int age, string address, managerType level) : Employee(age, address), managerLevel(level)
{
}

Manager::~Manager()
{
}

void Manager::setLevel(managerType level)
{ 
    managerLevel = level;
}

Manager::managerType Manager::getLevel()
{
    return managerLevel;
}

// FIX WHEN MANAGER TYPES ARE DECIDED
string Manager::getLevelString()
{
    string managerStr[] = { "shift_manager", "store_manager", "VP", "CEO" };
    return managerStr[(int)managerLevel];
}

void Manager::editItem(int &item)
{
    item.edit();
}

