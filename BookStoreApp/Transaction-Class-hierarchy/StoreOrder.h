//
//  StoreOrder.h
//  Team Project
//
//  Created by Pegah Sattari on 11/19/14.
//

#ifndef StoreOrder_H
#define StoreOrder_H

#include "Order.h"
#include <string>

class StoreOrder: public Order<Book> {
    private:
        string orderFrom;
    public:
        StoreOrder();
        StoreOrder(string name);
        virtual ~StoreOrder();
};

#endif
