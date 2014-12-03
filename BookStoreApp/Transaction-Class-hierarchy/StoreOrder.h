//
//  StoreOrder.h
//  Team Project
//

#ifndef StoreOrder_H
#define StoreOrder_H

#include "Order.h"
#include "Employee.h"
#include "..\Item-Class-Hierarchy\Book.h"
#include <string>

class StoreOrder: public Order<Book *> {
    private:
        string orderFrom;
        Employee * employee;
    public:
        StoreOrder();
        StoreOrder(string name, Employee *givenEmployee);
        virtual ~StoreOrder();
        friend ostream & operator<< (ostream & os, const StoreOrder & s);
        void setOrderFrom(string givenOrderFrom);
        string getOrderFrom() const;
};

#endif
