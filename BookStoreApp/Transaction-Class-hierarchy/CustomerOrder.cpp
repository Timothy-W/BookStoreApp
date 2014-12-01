//
//  CustomerOrder.cpp
//  Team Project
//
//  Created by Pegah Sattari on 11/19/14.
//

#include "CustomerOrder.h"
#include "../Person-Class-Hierarchy/Person.h"
#include "../Item-Class-Hierarchy/Book.h"

CustomerOrder::CustomerOrder() {
    int i;
    for (i=0; i<1024; i++)
        customerList[i] = NULL;
}

CustomerOrder::~CustomerOrder() {
    int i;
    for (i=0; i<1024; i++)
        if (customerList[i] != NULL)
            delete [] customerList[i]; //missing []
}

Book * CustomerOrder::PullCustomerOrder(Person &customerRef) const {
    //int i;
    //for (i=0; i<1024; i++)
        //if (customerList[i]->name == customerRef.name) //Or: *customerList[i]==customerRef if we overload operator== in Person class
            // Pull that customer's order!
    return NULL;   // Just for now to compile
}

ostream & operator<< (ostream & os, const CustomerOrder & c) {
    Book * b = c.getItem();
    os << b->getISBN() << " " << b->getAuthor() << " " << b->getTitle() << " " << b->getGenre() << " " << b->getPublisher();
    return os;
}

int CustomerOrder::generateRandomID() const {
    int id ;
    srand (time(NULL) + rand());   // generate a seed
    id = rand();                   // generate a random number
    return id;
}

