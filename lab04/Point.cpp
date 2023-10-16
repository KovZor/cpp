#include "Point.h"
#include <cmath>

using namespace std;

double Point::distanceTo(const Point &point) const{
    return sqrt( pow(x - point.x, 2) + pow(y - point.y, 2) );
}

Point::Point(int x, int y){
    if( x <= M && y <= M){
        this->x = x;
        this->y = y;
    }
}