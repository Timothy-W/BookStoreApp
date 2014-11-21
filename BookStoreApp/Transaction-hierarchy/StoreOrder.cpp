//
//  StoreOrder.cpp
//  Team Project
//
//  Created by Pegah Sattari on 11/19/14.
//

#include "StoreOrder.h"
#include <string>
using namespace std;

StoreOrder::StoreOrder(): orderFrom("") {}

StoreOrder::StoreOrder(string name): orderFrom(name) {}

StoreOrder::~StoreOrder() { cout << "StoreOrder destructor"; }