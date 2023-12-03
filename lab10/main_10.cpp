#include <iostream>
#include "Person.h"
#include "Employee.h"
#include "Manager.h"

using namespace std;

int main() {
    // employees
    Employee e1( "Kovacs", "Zoran", 2003, "IT" );
    // cout << e1 << endl;
    Employee e2( "Doe", "John", 1990, "Engineer" );
    // cout << e2 << endl;
    // manager
    Manager m1( "Elton", "John", 2000, "Manager" );
    m1.addEmployee( &e1 );
    m1.addEmployee( &e2 );
    m1.print( cout );
    cout << m1.numEmployees() << endl;
    m1.deleteEmployee( &e2 );
    m1.print( cout );
    cout << m1.numEmployees() << endl;


    return 0;
}