#pragma once
#include "Person.h"
class Employee :
    public Person
{
public:
    Employee();
    Employee(int age, string address, string name);
    virtual ~Employee();
protected:
    int employeeID;
public:
    void setID();
    void setID(int ID);

    int getID() const;
    friend ostream& operator<<(ostream& os, const Employee& emp);
private:
    int generateRandID();
};

