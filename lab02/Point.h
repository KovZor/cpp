//
// Created by kovzor on 2023. 10. 02..
//

#ifndef FEJLETT_PROG_TECH_POINT_H
#define FEJLETT_PROG_TECH_POINT_H

class Point{
private:
    int x, y;
public:
    Point( int x=0, int y=0);
    int getX() const;
    int getY() const;
};

void print() const;



#endif //FEJLETT_PROG_TECH_POINT_H
