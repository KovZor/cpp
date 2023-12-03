#ifndef LAB5_USER_H
#define LAB5_USER_H

#include <iostream>
#include <map>

using namespace std;

class User {
private:
    int id;
    string name;
    map<string, double> scores;
    static int counter;
public:
    // constructor
    User(const string& name) { this->name = name; this->id = counter++; }

    // functions - getters
    int getId() const { return this->id; }
    const string& getName() const { return this->name; }
    double getScore(const string& quizName) const;

    // setters
    void addScore(const string& quizName, double score);

    // printers
    void print(ostream& os) const;
    friend ostream& operator<<(ostream& os, const User& user);
};

#endif //LAB5_USER_H
