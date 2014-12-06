//
//  Order.h, Order.cpp
//  Team Project

#include <string>
#include <iostream>
#include "Person.h"
#include "Book.h"
using namespace std;

#ifndef Order_H
#define Order_H

template <class T>
class Order {
    protected:
        T item;
        int orderQuantity;
        int orderID;
    private:
        int generateRandomID() const;
    public:
        Order();
        Order(T, int quantity);
        virtual ~Order();
        void setItem(const T &Tref);
        T getItem() const;
        void setOrderQuantity(int givenQuantity);
        int getOrderQuantity() const;
        void setOrderID(int givenID);
        int getOrderID() const;
};




template <class T>
Order<T>::Order() { cout << "Order constructor"; }

template <class T>
Order<T>::Order(T t, int quantity) : item(t), orderQuantity(quantity), orderID(generateRandomID())  {}

template <class T>
Order<T>::~Order() { cout << "Order destructor"; }

template <class T>
void Order<T>::setItem(const T &Tref) {
    item = Tref;
}

template <class T>
T Order<T>::getItem() const {
    return item;
}

template<class T>
void Order<T>::setOrderQuantity(int givenQuantity) {
    orderQuantity = givenQuantity;
}

template<class T>
int Order<T>::getOrderQuantity() const{
    return orderQuantity;
}

template<class T>
void Order<T>::setOrderID(int givenID) {
    orderID = givenID;
}

template<class T>
int Order<T>::getOrderID() const{
    return orderID;
}

template<class T>
int Order<T>::generateRandomID() const {
    int id ;
    srand (time(NULL) + rand());   // generate a seed
    id = rand();                   // generate a random number
    return id;
}


#endif