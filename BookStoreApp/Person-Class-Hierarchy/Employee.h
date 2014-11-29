#pragma once
#include "Person.h"
class Employee :
    public Person
{
public:
    Employee();
    Employee(int dob, string address, string name);
    virtual ~Employee();
protected:
    int employeeID;
public:
    void setID();
    void setID(int ID);

    int getID() const;
private:
    int generateRandID();
};

