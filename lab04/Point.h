#ifndef LAB4_POINT_H
#define LAB4_POINT_H

#define M 2000

class Point {
private:
    int x, y;
public:
    Point(int x = 0, int y = 0);

    int getX() const { return x; };
    int getY() const { return y; };
    double distanceTo(const Point &point) const;
};

#endif //LAB4_POINT_H
