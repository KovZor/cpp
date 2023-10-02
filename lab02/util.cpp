//
// Created by kovzor on 2023. 10. 02..
//

#include "util.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

double distance(const Point& a, const Point& b){
    return 1.2;
}

bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d){
    return false;
}

void testIsSquare(const char * filename){
    ifstream file(filename);

    if( !file ){
        cerr << "Error opening file: " << filename << endl;
    }

    while ( true ){
        int x1, y1, x2, y2, x3, y3, x4, y4;
        file >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

        if(!file){
            break;
        }

        Point a(x1, y1);
        Point b(x2, y2);
        Point c(x3, y3);
        Point d(x4, y4);

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
    if (a->x != b->x) {
        return a.x < b.x;
    }
    return a.y < b.y;
}

void sortPoints(Point* points, int numPoints){
    sort(points, points + numPoints, comPoints);
}
