//
//  StoreOrder.h
//  Team Project
//
//  Created by Pegah Sattari on 11/19/14.
//

#ifndef StoreOrder_H
#define StoreOrder_H

#include "Order.h"
#include "..\Item-Class-Hierarchy\Book.h"
#include <string>

class StoreOrder: public Order<Book *> {
    private:
        string orderFrom;
        int generateRandomID() const;
    public:
        StoreOrder();
        StoreOrder(string name);
        virtual ~StoreOrder();
        friend ostream & operator<< (ostream & os, const StoreOrder & s);
        void setOrderFrom();
        string getOrderFrom() const;
};

#endif
