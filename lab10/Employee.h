#ifndef LAB10_EMPLOYEE_H
#define LAB10_EMPLOYEE_H

#include "Person.h"
#include <string>

class Employee : public Person {
private:
    string profession;
public:
    Employee(const string &name, const string &firstName, int birthYear, const string &profession) :
        Person(name, firstName, birthYear ), profession( profession ) {}
    virtual void print( ostream &os ) const override;
};

#endif //LAB10_EMPLOYEE_H
