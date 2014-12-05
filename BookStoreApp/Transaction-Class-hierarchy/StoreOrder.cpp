//
//  StoreOrder.cpp
//  Team Project
//

#include "StoreOrder.h"
#include "eBook.h"
#include "AudioBook.h"
#include "PaperBook.h"
using namespace std;

StoreOrder::StoreOrder(): Order(), orderFrom(""), person(NULL) {}

StoreOrder::StoreOrder(string name, Person *givenPerson): Order(), orderFrom(name), person(givenPerson) {}

StoreOrder::StoreOrder(Item *givenItem, int quantity, string name, Person *givenPerson): Order(givenItem, quantity), orderFrom(name), person(givenPerson) {}

StoreOrder::~StoreOrder() {
    if (person != NULL)
        delete person;
    cout << "StoreOrder destructor";
}

void StoreOrder::setOrderFrom(string givenOrderFrom) {
    orderFrom = givenOrderFrom;
}

string StoreOrder::getOrderFrom() const {
   return orderFrom;
}

void StoreOrder::setPerson(Person *givenPerson) {
    person = givenPerson;
}

Person * StoreOrder::getPerson() const {
    return person;
}

ostream & operator<< (ostream & os, const StoreOrder & s) {
    Item * itm = s.getItem();
    eBook * eb = dynamic_cast <eBook *> (itm);
    PaperBook * pb = dynamic_cast <PaperBook *> (itm);
    AudioBook * ab = dynamic_cast <AudioBook *> (itm);
    if (eb) {
        os << "\n" << (*eb) << "\n";
    }
    else if (pb) {
        os << "\n" << (*pb) << "\n";
    }
    else if (ab) {
        os << "\n" << (*ab) << "\n";
    }
    return os;
}


