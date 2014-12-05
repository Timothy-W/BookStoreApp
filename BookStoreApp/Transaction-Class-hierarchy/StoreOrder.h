//
//  StoreOrder.h
//  Team Project
//

#ifndef StoreOrder_H
#define StoreOrder_H

#include "Order.h"
#include "Item.h"
#include "Person.h"
#include <string>

class StoreOrder: public Order<Item *> {
    private:
        string orderFrom;
        Person * person;
    public:
        StoreOrder();
        StoreOrder(string name, Person *givenPerson);
        StoreOrder(Item *givenItem, int quantity, string name, Person *givenPerson);
        virtual ~StoreOrder();
        void setOrderFrom(string givenOrderFrom);
        string getOrderFrom() const;
        void setPerson(Person *givenPerson);
        Person * getPerson() const;
        friend ostream & operator<< (ostream & os, const StoreOrder & s);
};

#endif
