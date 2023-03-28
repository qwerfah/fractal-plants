#ifndef GEOMETRYPRIMITIVE_H
#define GEOMETRYPRIMITIVE_H


#include "position.h"
#include "projection/projection.h"


class DrawScene;


class GeometryPrimitive
{
public:
    GeometryPrimitive() = default;
    virtual ~GeometryPrimitive() = default;

    virtual void rotateX(double angle)
    {
        (void)angle;
    }

    virtual void rotateY(double angle)
    {
        (void)angle;
    }

    virtual void rotateZ(double angle)
    {
        (void)angle;
    }

    virtual void scale(double kx, double ky, double kz)
    {
        (void)kx;
        (void)ky;
        (void)kz;
    }

    virtual void translate(double x, double y, double z)
    {
        (void)x;
        (void)y;
        (void)z;
    }
};


#endif // GEOMETRYPRIMITIVE_H
