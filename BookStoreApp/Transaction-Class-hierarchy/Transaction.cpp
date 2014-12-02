/*
 *  Transaction.cpp
 *  teamProject
 *
 */

#include "Transaction.h"
#include "..\Person-Class-Hierarchy\Person.h" //dont need these as they are already included in Transaction.h
#include "..\Item-Class-Hierarchy\Book.h"

#include <iostream>
#include <ctime>
#include <string>
using namespace std;

Transaction::Transaction(): transactionID(generateRandomID()), transactionDate(0) {}

Transaction::~Transaction() { cout << "Transaction Destructor"; }

int Transaction::generateRandomID() const {
    int id ;
    srand (time(NULL) + rand());   // generate a seed
    id = rand();                   // generate a random number
    return id;
}

//missing &
Book * Transaction::PullCustomerOrder(Person &givenCustomer) const {
    return NULL;
}

Book * Transaction::PullDatedOrder(time_t givenDate) const {
    return NULL;
}

Book * Transaction::PullBookOrder(string givenTitle) const {
    return NULL;
}

//missing *
bool Transaction::ProcessOrder(Book * givenBook) {
    return false;
}

//void Transaction::setTransactionID(int givenID){
//    transactionID = givenID;
//}
//
//int Transaction::getTransactionID() const{
//   return this->transactionID;
//}