

#ifndef InventoryList_H
#define InventoryList_H


#include "List.h"
#include "../Person-Class-Hierarchy/Person.h"
#include "../Person-Class-Hierarchy/Employee.h"
#include "../Person-Class-Hierarchy/Manager.h"
#include <fstream>


class EmployeeList : public List<Person*>{

public:
   EmployeeList();
   EmployeeList( string name, string databasePath);
   virtual ~EmployeeList();

   void BuildFromDatabase();
   void SetDatabasePath( string path );
   string GetDatabasePath() const;
   Person* Search( int employeeID );
   virtual void RemoveFromList( Person* person );

private:
   string DatabasePath;
   void ManagerType(managerType& managerLevel, string identifier);
};

#endif