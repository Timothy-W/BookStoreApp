//
//  CustomerOrder.cpp
//  Team Project
//

#include "CustomerOrder.h"
#include "../Person-Class-Hierarchy/Person.h"
#include "../Item-Class-Hierarchy/Book.h"

CustomerOrder::CustomerOrder() {
<<<<<<< HEAD
 /*   int i;
    for (i=0; i<1024; i++)
        customerList[i] = NULL;*/
}

CustomerOrder::~CustomerOrder() {
    /*int i;
    for (i=0; i<1024; i++)
        if (customerList[i] != NULL)
            delete [] customerList[i];*/ 
=======
    Order();
    customer = NULL;
//    int i;
//    for (i=0; i<1024; i++)
//        customerList[i] = NULL;
}

CustomerOrder::CustomerOrder(Person *givenCustomer) {
    Order();
    customer = givenCustomer;
}

CustomerOrder::~CustomerOrder() {
//    int i;
    if (customer != NULL)
        delete customer;
//    for (i=0; i<1024; i++)
//        if (customerList[i] != NULL)
//            delete [] customerList[i]; //missing []
>>>>>>> 7285e63642ef85e3d84cac7ced76d4c8c61f2ba0
}

CustomerOrder::CustomerOrder(Book * book, int quantity, Person*pers) : Order(book, quantity), customer(pers){}
  

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

