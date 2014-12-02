//
//  ReturnOrder.h
//  Team Project
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
        void setRefundAmount(int givenAmount);
        int getRefundAmount() const;
};

#endif 
