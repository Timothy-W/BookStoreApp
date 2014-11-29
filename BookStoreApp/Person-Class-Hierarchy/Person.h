#pragma once
#include <iostream>

using namespace std;
class Person
{
public:
    Person();
    Person(int age, string address, string name);
    virtual ~Person();
protected:
    int DOB; //day of birth MMDDYYYY
    string address; //
    string name; // First Last

public:
    int getDOB() const;
    void setDOB(int age);

    string getAddress() const;
    void setAddress(string address);

    string getName() const;
    void setName(string);
};

