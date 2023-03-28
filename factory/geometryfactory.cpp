#include "geometryfactory.h"

GeometryPrimitive* GeometryPrimitivesFactory::get(GeometryPrimitives id)
{
    switch (id)
    {
    case POINT2D:
        return new Point2d();
        break;

    case POINT3D:
        return new Point3d();
        break;

    case EDGE2D:
        return new Edge2d();
        break;

    default:
        throw FactoryWrongValue("Geometry factory. Requested wrong value", id);
    }
}
