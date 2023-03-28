#ifndef EDGE2D_H
#define EDGE2D_H


#include "point2d.h"


class Edge2d : public GeometryPrimitive
{
public:
    Edge2d();
    Edge2d(Point2d p1, Point2d p2);

    Point2d p1() const;
    Point2d p2() const;

    double length() const;

private:
    Point2d _p1;
    Point2d _p2;
};

#endif // EDGE2D_H
