#ifndef POINT3D_H
#define POINT3D_H


#include "geometryprimitive.h"
#include "point2d.h"

class Point3d : public GeometryPrimitive
{
public:
    Point3d();
    Point3d(double x, double y, double z);

    virtual void translate(double x, double y, double z) override;
    virtual void scale(double kx, double ky, double kz) override;

    virtual void rotateX(double angle) override;
    virtual void rotateY(double angle) override;
    virtual void rotateZ(double angle) override;

    Point3d operator+(const Point3d& right) const;
    Point3d operator-(const Point3d& right) const;
    Point3d& operator=(const Point3d& right);
    Point3d& operator+=(const Point3d& right);
    Point3d& operator-=(const Point3d& right);

    Point3d operator/(double num) const;
    bool operator<(const Point3d& right) const;
    bool operator>(const Point3d& right) const;
    bool operator==(const Point3d& right) const;

    void setX(double x);
    void setY(double y);
    void setZ(double z);

    double x() const;
    double y() const;
    double z() const;

    Point2d to2d() const;

private:
    double _x;
    double _y;
    double _z;
};


#endif // POINT3D_H
