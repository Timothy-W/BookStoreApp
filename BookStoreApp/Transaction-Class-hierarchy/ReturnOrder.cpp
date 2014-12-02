//
//  ReturnOrder.cpp
//  Team Project
//

#include "ReturnOrder.h"
#include <iostream>
using namespace std;

template <class T>
ReturnOrder<T>::ReturnOrder() {
    Transaction();
    cout << "ReturnOrder constructor";
}

template <class T>
ReturnOrder<T>::~ReturnOrder() { cout << "ReturnOrder destructor"; }

template<class T>
void ReturnOrder<T>::setRefundAmount(int givenAmount){
//   int tempRefundAmount;
//   cout << "What is the new refund amount?" << endl;
//   cin >> tempRefundAmount;
//   this->refundAmount = tempRefundAmount;
    refundAmount = givenAmount;
}

template<class T>
int ReturnOrder<T>::getRefundAmount() const {
   return this->refundAmount;
}