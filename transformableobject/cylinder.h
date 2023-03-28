#ifndef CYLINDER_H
#define CYLINDER_H

#include "transformableobject.h"
#include "geometry/point3d.h"
#include "enums.h"

class Cylinder : public TransformableObject
{
public:
    Cylinder();
    Cylinder(const Point3d& start, const Point3d& end,
             double rd1, double rd2, QColor color = QColor(0, 0, 0),
             DrawMode mode = CARCASS);
    ~Cylinder() = default;

    virtual void translate(double x, double y, double z) override;
    virtual void scale(double kx, double ky, double kz) override;

    virtual void rotateX(double angle) override;
    virtual void rotateY(double angle) override;
    virtual void rotateZ(double angle) override;

    void draw(DrawScene& scene,
              std::shared_ptr<Projection>& projection,
              const Position& pos) override;

    virtual bool operator<(const TransformableObject& other) override;
    virtual TransformableObject& operator=(const TransformableObject& other) override;

    Point3d getP1() const;
    Point3d getP2() const;
    double getR1() const;
    double getR2() const;
    QColor getColor() const;
    DrawMode getDrawMode() const;
    double getZ() const;
    virtual double getDepth(double x, double y) override;

    void setP1(const Point3d& p);
    void setP2(const Point3d& p);
    void setR1(double r);
    void setR2(double r);
    void setColor(QColor color);
    void setDrawMode(DrawMode mode);

private:
    Point3d p1;
    Point3d p2;
    double r1;
    double r2;
    double z;
    QColor color;
    DrawMode mode;

    void setZ();
};

#endif // CYLINDER_H
