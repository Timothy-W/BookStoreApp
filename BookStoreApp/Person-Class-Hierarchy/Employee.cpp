#include "Employee.h"
#include <ctime>


Employee::Employee() : employeeID(-1){}

Employee::Employee(int age, string address, string name) : Person(age, address, name)
{
    setID();
}

Employee::~Employee()
{}

void Employee::setID()
{
    employeeID = generateRandID();
}

void Employee::setID(int ID)
{
    employeeID = ID;
}

int Employee::getID()
{
    return employeeID;
}

int Employee::generateRandID()
{
    int id;
    srand(time(NULL) + rand()); 
    id = rand() % INT_MAX;             
    return id;
}

