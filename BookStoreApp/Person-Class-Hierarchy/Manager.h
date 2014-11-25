#pragma once
#include "Employee.h"
class Manager :
    public Employee
{
public:
    Manager();
    Manager(int age, string address);
    virtual ~Manager();
protected:
    enum managerType { guy, shift_manager, store_manager, VP, CEO} managerLevel;

};

