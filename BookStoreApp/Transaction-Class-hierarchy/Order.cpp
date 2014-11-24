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
Order<T>::Order(T t, string s, int quantity): item(t), orderID(s), orderQuantity(quantity) {}

template <class T>
Order<T>::~Order() { cout << "Order destructor"; }

template <class T>
void Order<T>::setItem(const T &Tref) {
    item=Tref;
}

template <class T>
T Order<T>::getItem() const {
    return item;
}


