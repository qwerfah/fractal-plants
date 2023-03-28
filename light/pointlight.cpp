#include "pointlight.h"

PointLight::PointLight() : Light(POINT)
{
    color = QColor(255, 255, 255);
    position = Point3d(0, 0, 0);
    intensity = 1.0;
}

PointLight::PointLight(const QColor& clr, const Point3d& pos, double i)
    : Light(POINT), color(clr), position(pos), intensity(i)
{
}

void PointLight::setColor(const QColor& clr)
{
    color = clr;
}

void PointLight::setPosition(const Point3d& pos)
{
    position = pos;
}

void PointLight::setIntensity(double i)
{
    intensity = i;
}

QColor PointLight::getColor() const
{
    return color;
}

Point3d PointLight::getPosition() const
{
    return position;
}

double PointLight::getIntensity() const
{
    return intensity;
}
