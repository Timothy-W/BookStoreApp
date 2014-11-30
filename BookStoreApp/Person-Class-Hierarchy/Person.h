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

    virtual string getAddress() const;
    virtual void setAddress(string address);

    virtual string getName() const;
    virtual void setName(string);

    virtual int getID() const { return -1; };
};

