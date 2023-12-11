#ifndef LAB12_SETTLEMENT_H
#define LAB12_SETTLEMENT_H

// includes
#include <string>

using namespace std;

// declarations
class Settlement {
    string name = "";
    string county = "";
    int population = 0;
public:
    // constructor
    Settlement(const string &name, const string &county, int population);

    // getters
    const string &getName() const;
    const string &getCounty() const;
    int getPopulation() const;

    // setters
    void setCounty(const string &county);
    void setName(const string &name);
    void setPopulation(int population);

    // functions
    friend ostream& operator<<(ostream& os, const Settlement& settlement);
};


#endif //LAB12_SETTLEMENT_H
