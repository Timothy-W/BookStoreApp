#pragma once
#include "Person.h"
#include <vector>

class Customer :
    public Person
{
public:
    Customer();
    Customer(int age, string address, string name);
    virtual ~Customer();
protected:
     vector<int> orders; // vector holds the IDs of customers' orders 
};
