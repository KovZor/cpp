//
// Created by kovzor on 2023. 10. 02..
//

#ifndef FEJLETT_PROG_TECH_UTIL_H
#define FEJLETT_PROG_TECH_UTIL_H

#include "Point.h"

double distance(const Point& a, const Point& b);
bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d);
void testIsSquare(const char * filename);
void deletePoints(Point* points);
Point *createArray(int numPoints);
void printArray(Point* points, int numPoints);
void sortPoints(Point* points, int numPoints);


#endif //FEJLETT_PROG_TECH_UTIL_H
