/*
 *  Transaction.cpp
 *  teamProject
 *
 *  Created by Pegah Sattari on 11/19/14.
 *
 */

#include "Transaction.h"
#include "Person-Class-Hierarchy\\Person.h" //dont need these as they are already included in Transaction.h
#include "Item-Class-Hierarchy\\Book.h"

#include <iostream>
#include <ctime>
#include <string>
using namespace std;

Transaction::Transaction(): transactionID(0), transactionDate(0) {}

Transaction::~Transaction() { cout << "Transaction Destructor"; }

Book * Transaction::PullCustomerOrder(Person givenCustomer) const {
    return NULL;
}

Book * Transaction::PullDatedOrder(time_t givenDate) const {
    return NULL;
}

Book * Transaction::PullBookOrder(string givenTitle) const {
    return NULL;
}

bool Transaction::ProcessOrder(Book givenBook) {
    return false;
}
