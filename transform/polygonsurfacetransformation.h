#ifndef POLYGONSURFACETRANSFORMATION_H
#define POLYGONSURFACETRANSFORMATION_H

#include "geometry/point3d.h"
#include "transformations.h"
#include <vector>

class PolygonSurfaceTransformation : public Transformation
{
public:
    PolygonSurfaceTransformation() = default;
    ~PolygonSurfaceTransformation() = default;

    virtual void translate(TransformableObject* model, double x, double y, double z) override;
    virtual void scale(TransformableObject* model, double kx, double ky, double kz) override;

    virtual void rotateX(TransformableObject* model, double angle) override;
    virtual void rotateY(TransformableObject* model, double angle) override;
    virtual void rotateZ(TransformableObject* model, double angle) override;
};

#endif // POLYGONSURFACETRANSFORMATION_H
