/*
 *  Transaction.h
 *  teamProject
 *
 *  Created by Pegah Sattari on 11/19/14.
 *
 */

#ifndef Transaction_H
#define Transaction_H

#include "..\Person-Class-Hierarchy\Person.h"
#include "..\Item-Class-Hierarchy\Book.h"

#include <ctime>
#include <string>

class Transaction {
    private:
        int transactionID;
        time_t transactionDate;
    public:
        Transaction();
        virtual ~Transaction();
        virtual Book * PullCustomerOrder(Person &customerRef) const = 0;
        virtual Book * PullDatedOrder(time_t givenDate) const = 0;
        virtual Book * PullBookOrder(string givenTitle) const = 0;
        virtual bool ProcessOrder(Book * givenBook) = 0;  //This should decrement the quantity of givenBook in the inventory
};

#endif