/*
 *  Transaction.h
 *  teamProject
 *
 */

#ifndef Transaction_H
#define Transaction_H

#include "..\Person-Class-Hierarchy\Person.h"
#include "..\Item-Class-Hierarchy\Book.h"

#include <ctime>
#include <string>

class Transaction {
    protected:
        int transactionID;
        time_t transactionDate;
        int generateRandomID() const;
    public:
        Transaction();
        virtual ~Transaction();
        virtual Book * PullCustomerOrder(Person &customerRef) const;
        virtual Book * PullDatedOrder(time_t givenDate) const;
        virtual Book * PullBookOrder(string givenTitle) const;
        virtual bool ProcessOrder(Book * givenBook) = 0;  //This should decrement the quantity of givenBook in the inventory
        void setTransactionID(int givenID);
        int getTransactionID() const;
};

#endif