//
//  Order.h
//  Team Project

#ifndef Order_H
#define Order_H

#include <string>
#include "Transaction.h"
#include "..\Person-Class-Hierarchy\Person.h"
#include "..\Item-Class-Hierarchy\Book.h"

template <class T>
class Order: public Transaction {
    protected:
        T item;
        int orderQuantity;
    public:
        Order();
        Order(T, int quantity);
        virtual ~Order();
        void setItem(const T &Tref);
        T getItem() const;
        //void setOrderID();
        //string getOrderID() const;
        void setOrderQuantity(int givenQuantity);
        int getOrderQuantity() const;
};


#endif
