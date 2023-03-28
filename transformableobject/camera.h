#ifndef CAMERA_H
#define CAMERA_H


#include "transformableobject/transformableobject.h"
#include "position.h"


class Camera : public TransformableObject
{
public:
    Camera();
    Camera(Position& pos);
    virtual ~Camera() = default;

    virtual void setPosition(Position& pos);
    virtual Position getPosition();

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

    virtual void draw(DrawScene& scene,
                      std::shared_ptr<Projection>& projection,
                      const Position &pos)
    {
        (void)scene;
        (void)projection;
        (void)pos;
    }

    virtual bool operator<(const TransformableObject& other)
    {
        (void)other;
        return true;
    }

    virtual TransformableObject& operator=(const TransformableObject& other)
    {
        return *this;
    }

    virtual double getDepth(double x, double y)
    {
        (void)x;
        (void)y;
        return 0;
    }

protected:
    Position _pos;
};


#endif // CAMERA_H
