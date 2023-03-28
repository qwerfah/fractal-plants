#ifndef PARALLELPROJECTION_H
#define PARALLELPROJECTION_H


#include "projection.h"
#include "geometry/point3d.h"


class ParallelProjection : public Projection
{
public:
    ParallelProjection();
    Point2d project(const Point3d& p);
};


#endif // PARALLELPROJECTION_H
