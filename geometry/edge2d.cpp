#include "edge2d.h"
#include <cmath>

Edge2d::Edge2d()
{
    _p1.setX(0);
    _p1.setY(0);

    _p2.setX(0);
    _p2.setY(0);
}

Edge2d::Edge2d(Point2d p1, Point2d p2)
{
    _p1.setX(p1.x());
    _p1.setY(p1.y());

    _p2.setX(p2.x());
    _p2.setY(p2.y());
}

Point2d Edge2d::p1() const
{
    return _p1;
}

Point2d Edge2d::p2() const
{
    return _p2;
}

double Edge2d::length() const
{
    return sqrt((_p2.x() - _p1.x()) * (_p2.x() - _p1.x()) +
                (_p2.y() - _p1.y()) * (_p2.y() - _p1.y()));
}


