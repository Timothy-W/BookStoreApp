#pragma once
#include "Employee.h"
class Manager :
    public Employee
{
protected:
    enum managerType { shift_manager, store_manager, VP, CEO } managerLevel;
public:
    Manager();
    Manager(int age, string address, string name, managerType level);
    virtual ~Manager();

    void setLevel(managerType lvl);
    managerType getLevel() const;
    string getLevelString() const;
	

    friend ostream& operator<<(ostream& os, const Manager& man);
    void editItem(int &Item);
};

