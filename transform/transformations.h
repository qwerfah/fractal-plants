#ifndef TRANSFORMATIONS_H
#define TRANSFORMATIONS_H

#include "transformableobject/transformableobject.h"

class Transformation
{
  public:
    Transformation() = default;
    virtual ~Transformation() = default;

    virtual void translate(TransformableObject* model, double x, double y, double z) = 0;
    virtual void scale(TransformableObject* model, double kx, double ky, double kz) = 0;

    virtual void rotateX(TransformableObject* model, double angle) = 0;
    virtual void rotateY(TransformableObject* model, double angle) = 0;
    virtual void rotateZ(TransformableObject* model, double angle) = 0;
};


#endif // TRANSFORMATIONS_H
