//
//  CustomerOrder.cpp
//  Team Project
//
//  Created by Pegah Sattari on 11/19/14.
//

#include "CustomerOrder.h"
#include "Person.h"
#include "Book.h"

CustomerOrder::CustomerOrder() {
    int i;
    for (i=0; i<1024; i++)
        customerList[i] = NULL;
}

CustomerOrder::~CustomerOrder() {
    int i;
    for (i=0; i<1024; i++)
        if (customerList[i] != NULL)
            delete customerList[i];
}

Book * CustomerOrder::PullCustomerOrder(Person &customerRef) const {
    //int i;
    //for (i=0; i<1024; i++)
        //if (customerList[i]->name == customerRef.name) //Or: *customerList[i]==customerRef if we overload operator== in Person class
            // Pull that customer's order!
}
