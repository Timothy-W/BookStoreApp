#pragma once
#include "Person.h"
class Employee :
    public Person
{
public:
    Employee();
    Employee(int age, string address);
    virtual ~Employee();
protected:
    int employeeID;
public:
    void setID();
    void setID(int ID);
    int getID();
private:
    int generateRandID();
};

