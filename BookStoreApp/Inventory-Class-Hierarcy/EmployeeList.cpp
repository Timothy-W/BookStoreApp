



#include "EmployeeList.h"

EmployeeList::EmployeeList(): List(), DatabasePath(""){}






EmployeeList::EmployeeList( string name, string databasePath):
   List(name), DatabasePath(databasePath)
{

   this->BuildFromDatabase();

}




EmployeeList::~EmployeeList()
{
    SaveToTextFile();
}



void EmployeeList::SaveToTextFile()
{
    ofstream out(DatabasePath, ios::trunc);
    p = ItemList.begin();
    while (p != ItemList.end()) {
        Manager *p1 = dynamic_cast <Manager *> (*p);
        Employee *p2 = dynamic_cast <Employee *> (*p);
        if (p1 != NULL) {
            out << p1->getName()
                << ";" << p1->getAge()
                << ";" << p1->getID()
                << ";" << p1->getAddress()
                << ";" << "M"
                << ";" << p1->getLevelString()
                << endl;
        }
        else if (p2 != NULL) {
            out << p2->getName()
                << ";" << p2->getAge()
                << ";" << p2->getID()
                << ";" << p2->getAddress()
                << ";" << "E"
                << ";" << "Standard"
                << endl;
        }
    }
    out.close();
}




void EmployeeList::BuildFromDatabase()
{

   if( DatabasePath != "" )
   {

      ifstream inventoryFile(DatabasePath);
      string employeeType, name, address, level, buffer;
      int age, empID;
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
         empID = atoi( buffer.c_str() );

         getline (inventoryFile, buffer, ';');
         address = buffer;

         getline (inventoryFile, buffer, ';');
         employeeType = buffer;

         if( employeeType == "E" )
         {
            getline (inventoryFile, buffer, '\n');
            level = buffer;
            AddToList( new Employee(age, address, name, empID) );
         }
         else if( employeeType == "M" ){
            getline (inventoryFile, buffer, '\n');
            level = buffer;
            ManagerType( managerLevel, level);
            AddToList( new Manager(age, address, name, empID, managerLevel) );
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
    for (int i = 0; i < ItemList.size(); i++)
    {
        if (ItemList.at(i) == person)
            ItemList.erase(ItemList.begin() + i);
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


//Added this guy
void EmployeeList::DisplayList()
{

    for (p = ItemList.begin(); p != ItemList.end(); p++)
    {
        Manager  * mg  = dynamic_cast<Manager *>(*p);
        Employee * ep = dynamic_cast<Employee *>(*p);
        Customer * cs = dynamic_cast<Customer *>(*p);

        if (mg)
        {

            cout << "\n" << *mg << "\n";

        }
        else if (ep)
        {

            cout << "\n" << *ep << "\n";

        }
        else if (cs)
        {

            cout << "\n" << *cs << "\n";

        }
    }


}
