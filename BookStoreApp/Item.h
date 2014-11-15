#ifndef ITEM_H
#define ITEM_H




class Item
{
public:
   Item();
   ~Item();

   virtual void DisplayItem() = 0;
};

#endif // !ITEM_H