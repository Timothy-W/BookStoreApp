#include "Customer.h"

Customer::Customer() : age(-1), address (""), name(""){}

Customer::Customer(int age, string address, string name) : Person(age, address, name){}

Customer::~Customer()
{
}
