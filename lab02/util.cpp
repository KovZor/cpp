//
// Created by kovzor on 2023. 10. 02..
//

#include "Point.h"
#include "util.h"

#include <iostream>
#include <fstream>
#include <string>

#include <cmath>
#include <algorithm>
#include <utility>
#include <climits>

using namespace std;

double distance(const Point& a, const Point& b){
    return sqrt(pow( a.getX() - b.getX(), 2 ) + pow( a.getY() - b.getY(), 2) );
}

bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d){
    double ab = distance(a, b);
    double ac = distance(a, c);
    double ad = distance(a, d);
    double bc = distance(b, c);
    double bd = distance(b, d);
    double cd = distance(c, d);

    if (ab == ac && ab == ad && ab == bc && ab == bd && ab == cd) {
        double diagonal1 = distance(a, c);
        double diagonal2 = distance(b, d);
        if (diagonal1 == diagonal2) {
            return true;
        }
    }

    return false;
}

void testIsSquare(const char * filename){
    ifstream file(filename);

    if( !file ){
        cerr << "Error opening file: " << filename << endl;
    }

    Point points[4];
    int x, y;

    for (int i = 0; i < 4; ++i) {
        file >> x >> y;
        points[i].setX(x);
        points[i].setX(y);
    }

    file.close();

    if (isSquare(points[0], points[1], points[2], points[3])) {
        cout << "Points that create a square: ";
        for (int i = 0; i < 4; ++i) {
            cout << "(" << points[i].getX() << ", " << points[i].getY() << ") ";
        }
        cout << "YES" << std::endl;
    } else {
        cout << "Points that creater a square: ";
        for (int i = 0; i < 4; ++i) {
            cout << "(" << points[i].getX() << ", " << points[i].getY() << ") ";
        }
        cout << "NO" << endl;
    }
}

Point *createArray(int numPoints){
    Point *points = new Point[numPoints];
    return points;
}

void deletePoints(Point* points){
    if( points != nullptr ){
        delete[] points;
    }
}

void printArray(Point* points, int numPoints){
    for(int i = 0;i < numPoints;i++){
        cout << points[i].getX();
    }
    cout << endl;
}

bool comPoints(Point a, Point b){
    if (a.getX() != b.getX() ) {
        return a.getX() < b.getX();
    }
    return a.getX() < b.getX();
}

void sortPoints(Point* points, int numPoints){
    sort(points, points + numPoints, comPoints);
}

pair<Point, Point> closestPoints(Point* points, int numPoints) {
    if (numPoints < 2) {
        return std::make_pair( Point{-0, -0}, Point{0, 0} );
    }

    double minDistance = std::numeric_limits<double>::max();
    std::pair<Point, Point> closestPair;

    for (int i = 0; i < numPoints - 1; ++i) {
        for (int j = i + 1; j < numPoints; ++j) {
            double dist = distance(points[i], points[j]);
            if (dist < minDistance) {
                minDistance = dist;
                closestPair = std::make_pair(points[i], points[j]);
            }
        }
    }

    return closestPair;
}

pair<Point, Point> farthestPoints(Point* points, int numPoints) {
    if (numPoints < 2) {
        return make_pair(Point{0, 0}, Point{0, 0});
    }

    double maxDistance = 0.0;
    pair<Point, Point> farthestPair;

    for (int i = 0; i < numPoints - 1; ++i) {
        for (int j = i + 1; j < numPoints; ++j) {
            double dist = distance(points[i], points[j]);
            if (dist > maxDistance) {
                maxDistance = dist;
                farthestPair = make_pair(points[i], points[j]);
            }
        }
    }

    return farthestPair;
}

double distanceFromOrigin(const Point& point) {
    return sqrt(point.getX() * point.getX() + point.getY() * point.getY());
}

Point* farthestPointsFromOrigin(Point* points, int numPoints) {
    if (numPoints < 1) {
        return nullptr;
    }

    double maxDistance = 0.0;
    int numFarthestPoints = 0;

    for (int i = 0; i < numPoints; ++i) {
        double dist = distanceFromOrigin(points[i]);
        if (dist > maxDistance) {
            maxDistance = dist;
            numFarthestPoints = 1;
        } else if (dist == maxDistance) {
            numFarthestPoints++;
        }
    }

    Point *farthestPoints = new Point[numFarthestPoints];

    int index = 0;
    for (int i = 0; i < numPoints; ++i) {
        double dist = distanceFromOrigin(points[i]);
        if (dist == maxDistance) {
            farthestPoints[index] = points[i];
            index++;
        }
    }

    return farthestPoints;

}