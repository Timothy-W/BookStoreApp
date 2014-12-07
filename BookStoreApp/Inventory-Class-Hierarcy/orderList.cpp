



#include "OrderList.h"


OrderList::OrderList(): List<StoreOrder *>(), DatabasePath(""){}






OrderList::OrderList( string name, string databasePath, EmployeeList* employeeList, InventoryList* inventory):
   List<StoreOrder *>(name), DatabasePath(databasePath)
{
   empList = employeeList;
   invList = inventory;
   this->BuildFromDatabase();

}




OrderList::~OrderList()
{
   for( p = ItemList.begin(); p != ItemList.end(); ++p )
   {
      if(*p)
      {
         cout << "\nDeleteing p\n";
         delete *p;
      }
      *p = NULL;
   }

   cout << "\nOrder List Destructor \n";
}




void OrderList::BuildFromDatabase()
{

   if( DatabasePath != "" )
   {
      ifstream inventoryFile(DatabasePath);
      string orderedFrom, orderType, buffer, date;
      int employeeID, isbn, quantity, orderNum;
      Person* person;
      Item* item;

      if ( !inventoryFile ) {
         cerr << "ERROR: Failed to open input file\n";
         exit(-1);
      }

      while ( getline (inventoryFile, buffer, ';') )
      {

         isbn = atoi( buffer.c_str() );

         getline (inventoryFile, buffer, ';');
         employeeID = atoi( buffer.c_str() );

         getline (inventoryFile, buffer, ';');
         quantity = atoi( buffer.c_str() );

         getline (inventoryFile, buffer, ';');
         orderNum = atoi( buffer.c_str() );

         getline (inventoryFile, buffer, ';');
         date = buffer;

         getline (inventoryFile, buffer, '\n');
         orderedFrom = buffer;

         person = empList->Search(employeeID);
         item = invList->Search(isbn);


         if(person && item)
            AddToList( new StoreOrder(item, quantity, orderNum, date, orderedFrom, person) );
         else
            AddToList(NULL);

         ++ItemCount;
      }

      inventoryFile.close();
      
   }
   else
   {
      
      cout << "\nDatabase Path not set\n";
      
   }
   
}




StoreOrder* OrderList::Search(int orderNum)
{

   for (int i = 0; i < ItemList.size(); i++)
   {
      if (ItemList.at(i)->getOrderID() == orderNum)
         return ItemList.at(i);
   }

   return NULL;
   
}




void OrderList::RemoveFromList( StoreOrder * order )
{
   for (int i = 0; i < ItemList.size(); i++)
   {
      if (ItemList.at(i) == order)
         ItemList.erase(ItemList.begin() + i);
   }

}





void OrderList::SetDatabasePath( string path )
{

   DatabasePath = path;

}






string OrderList::GetDatabasePath() const
{

   return DatabasePath;
   
}





void OrderList::DisplayList()
{

   for (p = ItemList.begin(); p != ItemList.end(); p++)
   {
      if(*p)
         cout << "\n" << *p << "\n";
      else
         cout << "Nothing to print" << endl;

   }
   
   
}


