#pragma once
#include "Person.h"
#include <vector>

class Customer :
    public Person
{
public:
    Customer();
    Customer(int age, string address);
    virtual ~Customer();
protected:
     vector<int> pastOrders;
};
