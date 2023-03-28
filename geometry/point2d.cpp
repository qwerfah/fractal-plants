#include "point2d.h"


Point2d::Point2d() : _x(0), _y(0) {}


Point2d::Point2d(double x, double y)
{
    _x = x;
    _y = y;
}


void Point2d::setX(double x)
{
    _x = x;
}


void Point2d::setY(double y)
{
    _y = y;
}


double Point2d::x() const
{
    return _x;
}


double Point2d::y() const
{
    return _y;
}
