//
//  StoreOrder.cpp
//  Team Project
//
//  Created by Pegah Sattari on 11/19/14.
//

#include "StoreOrder.h"
#include <string>
using namespace std;

StoreOrder::StoreOrder(): orderFrom("") {}

StoreOrder::StoreOrder(string name): orderFrom(name) {}

StoreOrder::~StoreOrder() { cout << "StoreOrder destructor"; }

ostream & operator<< (ostream & os, const StoreOrder & s) {
    Book * b = s.getItem();
    os << b->getISBN() << " " << b->getAuthor() << " " << b->getTitle() << " " << b->getGenre() << " " << b->getPublisher();
    return os;
}

int StoreOrder::generateRandomID() const {
    int id ;
    srand (time(NULL) + rand());   // generate a seed
    id = rand();                   // generate a random number
    return id;
}

