#include "Person.h"


Person::Person() : age(0), address(""){}

Person::Person(int age, string address) : age(age), address(address){}

Person::~Person(){}

int Person::getAge()
{
    return 0;
}


void Person::setAge(int age)
{
    this->age = age;
}


void Person::setAddress(string address)
{
    this->address = address;
}


string Person::getAddress()
{
    return address;
}

