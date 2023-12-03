#include "Person.h"
#include <iostream>

using namespace std;

void Person::print( ostream &os ) const {
    os << this->name << " " << this->firstName << ":\n" << "Birth Year: "<< this->birthYear << " ";
}

ostream &operator<<( ostream &os, const Person &p ) {
    p.print( os );
}
