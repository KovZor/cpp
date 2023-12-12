// includes
#include "Student.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <map>

// definitions

Student::Student( int id, const string &firstName, const string &lastName ) :
    id( id ), lastName( lastName ), firstName( firstName ) {}

int Student::getId() const {
    return id;
}

void Student::setId( int id ) {
    this->id = id;
}

const string &Student::getFirstName() const {
    return firstName;
}

const string &Student::getLastName() const {
    return lastName;
}

void Student::addGrade(const string &subject, double grade) {
    grades[subject] = grade;
}

double Student::getGrade(const string &subject) {
    if( grades.find(subject) != grades.end() ){
        return grades[subject];
    } else {
        throw out_of_range("Subject not found.\n");
    }
}

const map<string, double> &Student::getGrades() const {
    return grades;
}

void Student::computeAverage() {
    double sum = 0;
    for( const auto &grade : grades ){
        sum += grade.second;
    }
    average = sum / grades.size();
}

double Student::getAverage() const {
    return average;
}

ostream &operator<<( ostream &os, const Student &student ){
    os << "ID: " << student.id << ", " << student.firstName << " " << student.lastName << ", Average: " << student.average;
    return os;
}



