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
    string address; //0 3 zip

public:
    int getDOB();
    void setDOB(int age);

    string getAddress();
    void setAddress(string address);

    string getName();
    void setName(string);
};

