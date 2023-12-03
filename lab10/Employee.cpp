#include "Employee.h"
#include <iostream>

void Employee::print( ostream &os ) const {
    Person::print( os );
    os << "\n" << "Profession: ";
    os << this->profession << endl;
}


