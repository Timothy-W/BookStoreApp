//
//  ReturnOrder.cpp
//  Team Project
//
//  Created by Pegah Sattari on 11/19/14.
//

#include "ReturnOrder.h"
#include <iostream>
using namespace std;

template <class T>
ReturnOrder<T>::ReturnOrder() { cout << "ReturnOrder constructor"; }

template <class T>
ReturnOrder<T>::~ReturnOrder() { cout << "ReturnOrder destructor"; }

template<class T>
void ReturnOrder<T>::setRefundAmount(){
   int tempRefundAmount;
   cout << "What is the new refund amount?" << endl;
   cin >> tempRefundAmount;
   this->refundAmount = tempRefundAmount;
}

template<class T>
int ReturnOrder<T>::getRefundAmount() const {
   return this->refundAmount;
}