#include "triangleconnection.h"

TriangleConnection::TriangleConnection(size_t a, size_t b, size_t c) : _a(a), _b(b), _c(c)
{
    _z = 0;
    _center = Point3d();
    _normal = Point3d();
}

size_t TriangleConnection::a() const
{
    return _a;
}

size_t TriangleConnection::b() const
{
    return _b;
}

size_t TriangleConnection::c() const
{
    return _c;
}

Point3d& TriangleConnection::center()
{
    return _center;
}

Point3d& TriangleConnection::normal()
{
    return _normal;
}

double& TriangleConnection::z()
{
    return _z;
}

bool TriangleConnection::operator<(const TriangleConnection& right)
{
    return _z < right._z;
}
