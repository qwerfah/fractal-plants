#ifndef ENUMS_H
#define ENUMS_H

#include <cmath>
#define TO_RADIANS (M_PI / 180.0)

enum Axis
{
    X = 0,
    Y,
    Z
};

enum Builders
{
    none = 0,
    FRACTALPLANTBUILDER,
    PSURFACEBUILDER
};

enum GeometryPrimitives
{
    NONE = 0,
    POINT2D,
    POINT3D,
    EDGE2D
};

enum TransformableObjects
{
    None = 0,
    CAMERA,
    FRACTALPLANTCARCASS,
    POLYGONSURFACE,
    COMPOSITEOBJECT
};

enum DrawMode
{
    CARCASS = 0,
    FILL
};

enum Generators
{
    FRACTALPLANTGENERATOR = 0
};

enum PointPosition
{
    LEFT = 0,
    RIGHT,
    BETWEEN
};

enum GeneratorPatterns
{
    USER = 0,
    TREE1,
    TREE2,
    TREE3,
    FERN
};

enum LightType
{
    POINT = 0,
    DIFFUSED
};

#endif // ENUMS_H
