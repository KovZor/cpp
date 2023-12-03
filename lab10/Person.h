#ifndef LAB10_PERSON_H
#define LAB10_PERSON_H

#include <string>

using namespace std;

class Person {
private:
    string name;
    string firstName;
    int birthYear;
public:
    Person(const string &name, const string &firstName, int birthYear) : name(name), firstName(firstName),
        birthYear(birthYear) {}
    virtual void print(ostream &os) const;
    friend ostream& operator<< ( ostream& os, const Person &p );


};

#endif //LAB10_PERSON_H
