



#include "EmployeeList.h"

EmployeeList::EmployeeList(): List(), DatabasePath(""){}






EmployeeList::EmployeeList( string name, string databasePath):
   List(name), DatabasePath(databasePath)
{

   this->BuildFromDatabase();

}




EmployeeList::~EmployeeList()
{

   cout << "\nEmployee List " << ListName << " Destroyed\n";

}





void EmployeeList::BuildFromDatabase()
{

   if( DatabasePath != "" )
   {

      ifstream inventoryFile(DatabasePath);
      string employeeType, name, address, level, buffer;
      int age;
      managerType managerLevel;

      if ( !inventoryFile ) {
         cerr << "ERROR: Failed to open input file\n";
         exit(-1);
      }

      while ( getline (inventoryFile, buffer, ';') )
      {

         name = buffer;

         getline (inventoryFile, buffer, ';');
         age = atoi( buffer.c_str() );

         getline (inventoryFile, buffer, ';');
         address = buffer;

         getline (inventoryFile, buffer, ';');
         employeeType = buffer;

         if( employeeType == "E" )
         {
            getline (inventoryFile, buffer, '\n');
            level = buffer;
            AddToList( new Employee(age, address, name) );
         }
         else if( employeeType == "M" ){
            getline (inventoryFile, buffer, '\n');
            level = buffer;
            ManagerType( managerLevel, level);
            AddToList( new Manager(age, address, name, managerLevel) );
         }
         else
            AddToList( NULL);
         
         ++ItemCount;
      }
      
      inventoryFile.close();

   }
   else
   {

      cout << "\nDatabase Path not set\n";

   }
   
}



void EmployeeList::RemoveFromList( Person* person )
{

   for( p = ItemList.begin(); p != ItemList.end(); p++ )
   {
      if(*p == person)
      {
         delete *p;
         ItemList.erase(p);
         --ItemCount;
      }
   }

}





void EmployeeList::SetDatabasePath( string path )
{

   DatabasePath = path;
   
}




string EmployeeList::GetDatabasePath() const
{

   return DatabasePath;

}


Person* EmployeeList::Search( int employeeID )
{

   for( p = ItemList.begin(); p != ItemList.end(); p++ )
   {
      Manager * mg = dynamic_cast<Manager *>(*p);
      Employee * ep = dynamic_cast<Employee *>(*p);

      if( (ep && ep->getID() == employeeID) )
      {

         return ep;
         
      }
      else if( (mg && mg->getID() == employeeID) )
      {

         return mg;

      }

   }

   return NULL;

}




void EmployeeList::ManagerType(managerType& managerLevel, string identifier)
{
   if( identifier == "Shift Manager" )
      managerLevel = shift_manager;
   else if( identifier == "Store Manager" )
      managerLevel = store_manager;
   else if( identifier == "VP" )
      managerLevel = VP;
   else
      managerLevel = CEO;
}







