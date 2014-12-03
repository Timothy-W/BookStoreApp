#include "Employee.h"
#include <ctime>
#include <string>
#include <fstream>

Employee::Employee() : employeeID(-1){}

Employee::Employee(int age, string address, string name) : Person(age, address, name)
{
    setID();
}

Employee::~Employee() {
    ofstream out("employeeListOut.txt", ios::trunc);
    out << "Employee;" << this->getID()
    << ";" << this->getName()
    << ";" << this->getAge()
    << ";" << this->getAddress()
    << endl;
    out.close();
}

void Employee::setID()
{
    employeeID = generateRandID();
}

void Employee::setID(int ID)
{
    employeeID = ID;
}

int Employee::getID() const
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

ostream& operator<<(ostream& os, const Employee& emp)
{
    os << "\nName: " << emp.getName() << "\nAddress: " << emp.getAddress() << "\nEmployee ID #: " << emp.getID() << endl;
    return os;
}