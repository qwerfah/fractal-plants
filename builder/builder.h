#ifndef BUILDER_H
#define BUILDER_H


#include "transformableobject/transformableobject.h"
#include "auxiliarystructures/auxiliarystructure.h"
#include "geometry/point3d.h"
#include <memory>


class Builder
{
public:
    Builder() = default;
    virtual ~Builder() = default;

    virtual std::shared_ptr<TransformableObject> build() = 0;
    virtual void push(const GeometryPrimitive& primitive) = 0;
    virtual void push(const AuxiliaryStructure& structure) = 0;
    virtual void push(const std::shared_ptr<TransformableObject>& object) = 0;

//    virtual void push(const Point3d &point) = 0;
//    virtual void push(const Connection &connection) = 0;
//    virtual void push(double x, double y, double z) = 0;
//    virtual void push(size_t start, size_t end) = 0;
};


#endif // BUILDER_H
