#ifndef POINTLIGHT_H
#define POINTLIGHT_H

#include "light.h"
#include "geometry/point3d.h"
#include <QColor>

class PointLight : public Light
{
public:
    PointLight();
    PointLight(const QColor& clr, const Point3d& pos, double i);
    ~PointLight() = default;

    void setColor(const QColor& clr);
    void setPosition(const Point3d& pos);
    void setIntensity(double i);

    QColor getColor() const;
    Point3d getPosition() const;
    double getIntensity() const;

private:
    QColor color;
    Point3d position;
    double intensity;
};

#endif // POINTLIGHT_H
