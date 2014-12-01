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
//
//  Order.cpp
//  Team Project
//
//  Created by Pegah Sattari on 11/19/14.
//  Copyright (c) 2014 Pegah. All rights reserved.
//

#include "Order.h"
#include <string>
#include <iostream>
using namespace std;

template <class T>
Order<T>::Order() { cout << "Order constructor"; }

template <class T>
Order<T>::Order(T t, string s, int quantity) : item(t), orderID(s), orderQuantity(quantity) {}

template <class T>
Order<T>::~Order() { cout << "Order destructor"; }

template <class T>
void Order<T>::setItem(const T &Tref) {
    item = Tref;
}

template <class T>
T Order<T>::getItem() const {
    return this->item;
}

template<class T>
void Order<T>::setOrderID(){
    string tempOrderID;
    cout << "What is the new order ID?" << endl;
    cin >> tempOrderID;
    this->orderID = tempOrderID;
}

template<class T>
string Order<T>::getOrderID() const {
    return this->orderID;
}

//template<class T>
//void Order<T>::setOrderName(){
//   string tempOrderName;
//   cout << "What is the new order name?" << endl;
//   cin >> tempOrderName;
//   this->orderName = tempOrderName;
//}

//template<class T>
//string Order<T>::getOrderName() const{
//   return this->orderName;
//}

template<class T>
void Order<T>::setOrderQuantity(){
    int tempOrderQuantity;
    cout << "What is the new order quantity?" << endl;
    cin >> tempOrderQuantity;
    this->orderQuantity = tempOrderQuantity;
}

template<class T>
int Order<T>::getOrderQuantity() const{
    return this->orderQuantiy;
}



#endif
