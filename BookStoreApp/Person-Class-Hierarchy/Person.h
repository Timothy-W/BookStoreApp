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
    int age; //day of birth MMDDYYYY
    string address; //
    string name; // First Last

protected:
    virtual void print(std::ostream& str) const ;
public:
    friend std::ostream& operator<<(std::ostream& os, Person const& person)
    {
        return os;
    }
public:
    int getAge() const;
    void setAge(int age);

    virtual string getAddress() const;
    virtual void setAddress(string address);

    virtual string getName() const;
    virtual void setName(string);

    virtual int getID() const { return -1; };
};

