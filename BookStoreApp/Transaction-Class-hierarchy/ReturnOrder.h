//
//  ReturnOrder.h
//  Team Project
//
//  Created by Pegah Sattari on 11/19/14.
//

// We can probably remove this class and use a function instead of it.

#ifndef ReturnOrder_H
#define ReturnOrder_H

#include "Transaction.h"

template <class T>
class ReturnOrder: public Transaction {
    private:
        int refundAmount;
    public:
        ReturnOrder();
        virtual ~ReturnOrder();
};

#endif 
