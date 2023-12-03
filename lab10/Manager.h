#ifndef LAB10_MANAGER_H
#define LAB10_MANAGER_H

#include <vector>
#include "Employee.h"

using namespace std;

class Manager : public Employee {
private:
    vector<Employee*> employees;
public:
    // constructor
    Manager( const string &name, const string &firstName, int birthYear, const string &profession  ) :
        Employee(name, firstName, birthYear, profession) {}

    virtual void print( ostream &os ) const override;
    void addEmployee( Employee *employee );
    void deleteEmployee( Employee *employee );
    int numEmployees(){ return this->employees.size(); }
};

#endif //LAB10_MANAGER_H
