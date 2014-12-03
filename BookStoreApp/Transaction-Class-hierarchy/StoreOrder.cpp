//
//  StoreOrder.cpp
//  Team Project
//

#include "StoreOrder.h"
#include "Book.h"
#include <string>
using namespace std;

StoreOrder::StoreOrder() {
    Order();
    orderFrom = "";
    employee = NULL;
}

StoreOrder::StoreOrder(string name, Employee *givenEmployee) {
    Order();
    orderFrom = name;
    employee = givenEmployee;
}

StoreOrder::~StoreOrder() {
    if (employee != NULL)
        delete employee;
    cout << "StoreOrder destructor";
}

ostream & operator<< (ostream & os, const StoreOrder & s) {
    Book * b = s.getItem();
    os << b->getISBN() << " " << b->getAuthor() << " " << b->getTitle() << " " << b->getGenre() << " " << b->getPublisher();
    return os;
}

void StoreOrder::setOrderFrom(string givenOrderFrom) {
//   string tempOrderFrom;
//   cout << "Where are you ordering from?" << endl;
//   cin >> tempOrderFrom;
//   this->orderFrom = tempOrderFrom;
    orderFrom = givenOrderFrom;
}

string StoreOrder::getOrderFrom() const
{
   return this->orderFrom;
}