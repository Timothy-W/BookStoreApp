#pragma once
#include "Employee.h"
class Manager :
    public Employee
{
protected:
    enum managerType { shift_manager, store_manager, VP, CEO } managerLevel;
public:
    Manager();
    Manager(int age, string address, managerType level);
    virtual ~Manager();

    void setLevel(managerType lvl);
    managerType getLevel();
    string getLevelString();
	
    void editItem(int &Item);
};

