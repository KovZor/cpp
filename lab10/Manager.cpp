#include "Manager.h"
#include <iostream>
#include <algorithm>

void Manager::print( ostream &os ) const {
    // printing the data
    os << "Manager: " << endl;
    Employee::print( os );
    os << endl << "Employees: " << endl;
    for( Employee *e : employees ){
        e->print( os );
        os << endl;
    }
}

void Manager::addEmployee( Employee *employee ) {
    // add an employee to the manager
    employees.push_back( employee );
}

void Manager::deleteEmployee( Employee *employee ){
    // delete an employee
    auto it = find( employees.begin(), employees.end(), employee );
    if ( it != employees.end() ) {
        employees.erase( it );
        delete employee;
    }
}

