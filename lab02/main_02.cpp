#include <iostream>
#include "Point.h"
#include "util.h"
#include <cstdlib>

using namespace std;

int main() {
    /*
    Point p1(2,3);
    p1.print();
    cout << endl;

    Point p2(100, 200);
    p2.print();
    cout << endl;

    Point *pp1 = new Point(300, 400);
    Point *pp2 = new Point(500, 1000);

    pp1->print();
    cout << endl;

    pp2->print();
    cout << endl;

    cout << distance( Point(1, 1), Point(1, 1) );

    delete pp1;
    delete pp2;
    */

    int numPoints = 10;

    cout << "Default: " << endl;
    Point *points = createArray(numPoints);
    printArray(points, numPoints);


    srand(time(0));
    for(int i = 0;i < numPoints;i++){
        points[i] = Point( rand() % 100,rand() % 100);
    }


    cout << "Sorted: " << endl;
    sortPoints(points, numPoints);
    printArray(points, numPoints);
    //for commit comment

    deletePoints(points);

    return 0;
}
