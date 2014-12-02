//
//  //Order.cpp
//  //Team Project

#include "Order.h"
#include <string>
#include <iostream>
using namespace std;

template <class T>
Order<T>::Order() {
    Transaction();
    cout << "Order constructor";
}

template <class T>
Order<T>::Order(T t, int quantity) : Transaction(), item(t), orderQuantity(quantity)  {}

template <class T>
Order<T>::~Order() { cout << "Order destructor"; }

template <class T>
void Order<T>::setItem(const T &Tref) {
    item = Tref;
}

template <class T>
T Order<T>::getItem() const {
    return this->item;
}

//template<class T>
//void Order<T>::setOrderID(){
//    string tempOrderID;
//    cout << "What is the new order ID?" << endl;
//    cin >> tempOrderID;
//    this->orderID = tempOrderID;
//}
//
//template<class T>
//string Order<T>::getOrderID() const {
//    return this->orderID;
//}

//template<class T>
//void Order<T>::setOrderName(){
//   string tempOrderName;
//   cout << "What is the new order name?" << endl;
//   cin >> tempOrderName;
//   this->orderName = tempOrderName;
//}

//template<class T>
//string Order<T>::getOrderName() const{
//   return this->orderName;
//}

template<class T>
void Order<T>::setOrderQuantity(int givenQuantity){
//    int tempOrderQuantity;
//    cout << "What is the new order quantity?" << endl;
//    cin >> tempOrderQuantity;
//    this->orderQuantity = tempOrderQuantity;
    orderQuantity = givenQuantity;
}

template<class T>
int Order<T>::getOrderQuantity() const{
    return this->orderQuantiy;
}


//#include "Order.h"
//#include <string>
//#include <iostream>
//using namespace std;
//
//template <class T>
//Order<T>::Order() { cout << "Order constructor"; }
//
//template <class T>
//Order<T>::Order(T t, string s, int quantity): item(t), orderID(s), orderQuantity(quantity) {}
//
//template <class T>
//Order<T>::~Order() { cout << "Order destructor"; }
//
//template <class T>
//void Order<T>::setItem(const T &Tref) {
//    item=Tref;
//}
//
//template <class T>
//T Order<T>::getItem() const {
//    return this->item;
//}
//
//template<class T>
//void Order<T>::setOrderID(){
//   string tempOrderID;
//   cout << "What is the new order ID?" << endl;
//   cin >> tempOrderID;
//   this->orderID = tempOrderID;
//}
//
//template<class T>
//string Order<T>::getOrderID() const {
//   return this->orderID;
//}
//
////template<class T>
////void Order<T>::setOrderName(){
////   string tempOrderName;
////   cout << "What is the new order name?" << endl;
////   cin >> tempOrderName;
////   this->orderName = tempOrderName;
////}
//
////template<class T>
////string Order<T>::getOrderName() const{
////   return this->orderName;
////}
//
//template<class T>
//void Order<T>::setOrderQuantity(){
//   int tempOrderQuantity;
//   cout << "What is the new order quantity?" << endl;
//   cin >> tempOrderQuantity;
//   this->orderQuantity = tempOrderQuantity;
//}
//
//template<class T>
//int Order<T>::getOrderQuantity() const{
//   return this->orderQuantiy;
//}
//
//
//
//
