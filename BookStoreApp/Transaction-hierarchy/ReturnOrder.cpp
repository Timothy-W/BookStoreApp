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