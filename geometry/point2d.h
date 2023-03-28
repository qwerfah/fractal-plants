#ifndef POINT2D_H
#define POINT2D_H


#include "geometryprimitive.h"


class Point2d : public GeometryPrimitive
{
public:
    Point2d();
    Point2d(double x, double y);

    void setX(double x);
    void setY(double y);

    double x() const;
    double y() const;

private:
    double _x;
    double _y;
};


#endif // POINT2D_H
