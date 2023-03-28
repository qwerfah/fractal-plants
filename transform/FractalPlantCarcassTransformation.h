#ifndef POLYGONTRANSFORMATION_H
#define POLYGONTRANSFORMATION_H


#include "geometry/point3d.h"
#include "transformations.h"
#include <vector>

class FractalPlantCarcassTransformation : public Transformation
{
  public:
    FractalPlantCarcassTransformation() = default;
    ~FractalPlantCarcassTransformation() = default;

    virtual void translate(TransformableObject* model, double x, double y, double z) override;
    virtual void scale(TransformableObject* model, double kx, double ky, double kz) override;

    virtual void rotateX(TransformableObject* model, double angle) override;
    virtual void rotateY(TransformableObject* model, double angle) override;
    virtual void rotateZ(TransformableObject* model, double angle) override;
};


#endif // POLYGONTRANSFORMATION_H
