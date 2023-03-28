#ifndef PROJECTION_H
#define PROJECTION_H


class Point3d;
class Point2d;


class Projection
{
public:
    Projection() = default;
    virtual ~Projection() = default;

    virtual Point2d project(const Point3d &p) = 0;
};


#endif // PROJECTION_H
