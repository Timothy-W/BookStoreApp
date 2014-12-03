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

//
//  //Order.cpp
//  //Team Project

#include <string>
#include <iostream>
using namespace std;

template <class T>
Order<T>::Order()
{
    cout << "Order constructor";
}

template <class T>
Order<T>::Order(T t, int quantity) : item(t), orderQuantity(quantity)  {}

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


//template<class T>
//void Order<T>::setOrderName(string n){
//   this->orderName = tempOrderName;
//}

//template<class T>
//string Order<T>::getOrderName() const{
//   return this->orderName;
//}

template<class T>
void Order<T>::setOrderQuantity(int givenQuantity){
    //    int tempOrderQuantity;
    //    cout << "What is the new order quantity?" << endl;
    //    cin >> tempOrderQuantity;
    //    this->orderQuantity = tempOrderQuantity;
    orderQuantity = givenQuantity;
}

template<class T>
int Order<T>::getOrderQuantity() const{
    return this->orderQuantiy;
}
