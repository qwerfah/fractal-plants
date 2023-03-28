#include "parallelprojection.h"

ParallelProjection::ParallelProjection()
{
}

Point2d ParallelProjection::project(const Point3d& p)
{
    return p.to2d();
}
