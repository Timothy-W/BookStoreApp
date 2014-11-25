#include "Person.h"

Person::Person() : DOB(0), address(""), name("")
{}

Person::Person(int dob, string address, string name) : DOB(dob), address(address), name(name)
{}

Person::~Person(){}

int Person::getDOB()
{
    return DOB;
}


void Person::setDOB(int age)
{
    this->DOB = age;
}


void Person::setAddress(string address)
{
    this->address = address;
}


string Person::getAddress()
{
    return address;
}

string Person::getName()
{
    return name;
}

void Person::setName(string name)
{
    this->name = name;
}
