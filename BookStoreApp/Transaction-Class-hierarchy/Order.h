//
//  Order.h
//  Team Project
//
//  Created by Pegah Sattari on 11/19/14.
//

#ifndef Order_H
#define Order_H

#include <string>
#include "Transaction.h"
#include "..\Person-Class-Hierarchy\Person.h"
#include "..\Item-Class-Hierarchy\Book.h"

template <class T>
class Order: public Transaction {
    private:
        T item;
        string orderID;
        //string orderName;
        int orderQuantity;
    public:
        Order();
        Order(T, string s, int quantity);
        virtual ~Order();
        void setItem(const T &Tref);
        T getItem() const;
        void setOrderID();
        string getOrderID() const;
        ///void setOrderName();
        //string getOrderName() const;
        void setOrderQuantity();
        int getOrderQuantity() const;
};

#endif
