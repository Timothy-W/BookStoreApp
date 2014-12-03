//
//  CustomerOrder.h
//  Team Project
//

#ifndef CustomerOrder_H
#define CustomerOrder_H

#include <string>
#include "Order.h"
#include "../Item-Class-Hierarchy/Book.h"
#include "../Person-Class-Hierarchy/Person.h"

class CustomerOrder: public Order<Book *> {
    private:

        Person * customer = NULL;
        // We also need a Book *orderList[100] for each cutomer (orders of each customer)
    public:
        CustomerOrder();
        CustomerOrder(Book * book, int quantity, Person*pers);

        // Person * customerList[1024];
        // We also need a Book *orderList[100] for each cutomer (orders of each customer)
    public:

        virtual ~CustomerOrder();
        virtual Book * PullCustomerOrder(Person &customerRef) const;
        void setCustomer();
        Person * getCustomer();
        friend ostream & operator<< (ostream & os, const CustomerOrder & c);
};

#endif
