#include "point3d.h"
#include <cmath>

Point3d::Point3d() : _x(0), _y(0), _z(0) {}

Point3d::Point3d(double x, double y, double z)
{
    _x = x;
    _y = y;
    _z = z;
}

void Point3d::translate(double x, double y, double z)
{
    _x += x;
    _y += y;
    _z += z;
}

void Point3d::scale(double kx, double ky, double kz)
{
    _x *= kx;
    _y *= ky;
    _z *= kz;
}

void Point3d::rotateX(double angle)
{
    double y = _y;

    _y = y * cos(angle) - _z * sin(angle);
    _z = y * sin(angle) + _z * cos(angle);
}

void Point3d::rotateY(double angle)
{
    double x = _x;

    _x = x * cos(angle) + _z * sin(angle);
    _z = -x * sin(angle) + _z * cos(angle);
}

void Point3d::rotateZ(double angle)
{
    double x = _x;

    _x = x * cos(angle) - _y * sin(angle);
    _y = x * sin(angle) + _y * cos(angle);
}

Point3d Point3d::operator+(const Point3d& right) const
{
    Point3d newPoint;
    newPoint._x = this->_x + right._x;
    newPoint._y = this->_y + right._y;
    newPoint._z = this->_z + right._z;

    return newPoint;
}

Point3d Point3d::operator-(const Point3d& right) const
{
    Point3d newPoint;
    newPoint._x = this->_x - right._x;
    newPoint._y = this->_y - right._y;
    newPoint._z = this->_z - right._z;

    return newPoint;
}

Point3d& Point3d::operator=(const Point3d& right)
{
    this->_x = right._x;
    this->_y = right._y;
    this->_z = right._z;

    return *this;
}

Point3d& Point3d::operator+=(const Point3d& right)
{
    this->_x += right._x;
    this->_y += right._y;
    this->_z += right._z;

    return *this;
}

Point3d& Point3d::operator-=(const Point3d& right)
{
    this->_x -= right._x;
    this->_y -= right._y;
    this->_z -= right._z;

    return *this;
}

Point3d Point3d::operator/(double num) const
{
    Point3d newPoint = *this;
    newPoint._x /= num;
    newPoint._y /= num;
    newPoint._z /= num;

    return newPoint;
}

bool Point3d::operator<(const Point3d& right) const
{
    return (_x < right._x && _y < right._y && _z < right._z);
}

bool Point3d::operator>(const Point3d& right) const
{
    return (_x > right._x && _y > right._y && _z > right._z);
}

bool Point3d::operator==(const Point3d& right) const
{
    return (_x == right._x && _y == right._y && _z == right._z);
}

void Point3d::setX(double x)
{
    _x = x;
}

void Point3d::setY(double y)
{
    _y = y;
}

void Point3d::setZ(double z)
{
    _z = z;
}

double Point3d::x() const
{
    return _x;
}

double Point3d::y() const
{
    return _y;
}

double Point3d::z() const
{
    return _z;
}

Point2d Point3d::to2d() const
{
    return Point2d(_x, _y);
}
