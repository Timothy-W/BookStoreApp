#pragma once
#include <iostream>

using namespace std;
class Person
{
public:
    Person();
    Person(int age, string address);
    virtual ~Person();
    
protected:
    int age;
    string address;
public:
    int getAge();
    void setAge(int age);
    void setAddress(string address);
    string getAddress();

};

