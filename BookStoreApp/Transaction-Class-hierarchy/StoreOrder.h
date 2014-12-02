//
//  StoreOrder.h
//  Team Project
//

#ifndef StoreOrder_H
#define StoreOrder_H

#include "Order.h"
#include "..\Item-Class-Hierarchy\Book.h"
#include <string>

class StoreOrder: public Order<Book *> {
    private:
        string orderFrom;
    public:
        StoreOrder();
        StoreOrder(string name);
        virtual ~StoreOrder();
        friend ostream & operator<< (ostream & os, const StoreOrder & s);
        void setOrderFrom(string givenOrderFrom);
        string getOrderFrom() const;
};

#endif
