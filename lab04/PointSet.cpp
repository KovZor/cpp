#include "PointSet.h"
#include <random>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

bool exists[M+1][M+1] = { false };

PointSet::PointSet(int n){
   this->n = n;
   points.reserve(n);
   distances.reserve( n * (n - 1) / 2);

    random_device rd; // seed the random number generator named rd
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, M);

    // return a number in the given range
    while( points.size() < n ){
        int x = dist(mt);
        int y = dist(mt);
        // ellenorzi, hogy az x es y koordinatak nem duplak
        points.push_back( Point(x, y) );
        if( exists[x][y] ){
            continue;
        } else {
            exists[x][y] = true;
            //points.push_back(p);
        }
    }

    int x = dist(mt);
    int y = dist(mt);

    computeDistances();
}

void PointSet::computeDistances() {
    for(int i = 0;i < n;i++){
        for(int j = i + 1;j < n;j++){
            distances.push_back( points[i].distanceTo(points[j]) );
        }
    }
}

double PointSet::minDistance() const {
    return *min_element( distances.begin(), distances.end() );
}

double PointSet::maxDistance() const {
    return * max_element( distances.begin(), distances.end() );
}

int PointSet::numDistances() const {
    return distances.size();
}

int PointSet::numDistinctDistances() {
    set<double> uniqueDistances;

    for (double distance : distances) {
        uniqueDistances.insert(distance);
    }

    return uniqueDistances.size();
}


void PointSet::sortDistances() {
    sort( distances.begin(), distances.end() );
}

void PointSet::printDistances() const {
    int index = 0;
    for(int i = 0;i < n;i++){
        for(int j = i + 1; j < n;j++){
            cout << "Distance between points " << i << " - " << j << distances[index] << ": " << distances[index] << endl;
            index++;
        }
    }
}

void PointSet::sortPointsX() {
    sort( points.begin(), points.end(), [](const Point &lhs, const Point &rhs) -> bool {
        return lhs.getX() < rhs.getX();
    });
}

void PointSet::sortPointsY() {
    sort( points.begin(), points.end(), [](const Point &lhs, const Point &rhs) -> bool {
        return lhs.getY() < rhs.getY();
    });
}

void PointSet::printPoints() const {
    for(int i = 0;i < n;i++){
        cout << "( " << points[i].getX() << ", " << points[i].getY() << ") " << " ";
    }
}










