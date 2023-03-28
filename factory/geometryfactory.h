#ifndef GEOMETRYFACTORY_H
#define GEOMETRYFACTORY_H


#include "geometry/edge2d.h"
#include "geometry/point2d.h"
#include "geometry/point3d.h"
#include "enums.h"
#include "factory.h"


class GeometryPrimitivesFactory : public Factory
{
public:
    static GeometryPrimitive *get(GeometryPrimitives id);
};


#endif // GEOMETRYFACTORY_H
