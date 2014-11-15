#pragma once
#include "Product.h"
class Book :
   public Product
{
public:
   Book();
   virtual ~Book();
   virtual void DisplayItem();
};

