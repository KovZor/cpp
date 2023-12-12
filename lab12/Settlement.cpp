#include "Settlement.h"
#include <iostream>

// definitions

// constructor
Settlement::Settlement(const string &name, const string &county, int population) :
    name(name), county(county), population(population) {}

// getters
const string &Settlement::getName() const { return name; }
const string &Settlement::getCounty() const { return county; }
int Settlement::getPopulation() const { return population; }

// setters
void Settlement::setName(const string &name) { Settlement::name = name; }
void Settlement::setCounty(const string &county) { Settlement::county = county; }
void Settlement::setPopulation(int population) { Settlement::population = population; }

// functions
ostream& operator<<(ostream& os, const Settlement& settlement) {
    os << "Name: " << settlement.getName() << ", County: " << settlement.getCounty()
       << ", Population: " << settlement.getPopulation();
    return os;
}


