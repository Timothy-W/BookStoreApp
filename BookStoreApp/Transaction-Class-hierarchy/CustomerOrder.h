//
//  CustomerOrder.h
//  Team Project
//
//  Created by Pegah Sattari on 11/19/14.
//

#ifndef CustomerOrder_H
#define CustomerOrder_H

#include <string>
#include "Order.h"
#include "Book.h"
#include "Person.h"

class CustomerOrder: public Order<Book *> {
    private:
        Person *customerList[1024];
        // We also need a Book *orderList[100] for each cutomer (orders of each customer)
        int generateRandomID() const;
    public:
        CustomerOrder();
        virtual ~CustomerOrder();
        virtual Book * PullCustomerOrder(Person &customerRef) const;
        friend ostream & operator<< (ostream & os, const CustomerOrder & c);
};

#endif
