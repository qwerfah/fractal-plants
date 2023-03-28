#include "polygonconnection.h"

PolygonConnection::PolygonConnection()
{

}

void PolygonConnection::push(size_t vertex)
{
    vertices.push_back(vertex);
}

size_t PolygonConnection::operator[](size_t index)
{
    if (index < vertices.size())
    {
        return vertices[index];
    }

    return 0;
}

void PolygonConnection::clear()
{
    vertices.clear();
}

size_t PolygonConnection::size() const
{
    return vertices.size();
}

Point3d& PolygonConnection::center()
{
    return _center;
}

Point3d& PolygonConnection::normal()
{
    return _normal;
}

double& PolygonConnection::z()
{
    return _z;
}

bool PolygonConnection::operator<(const PolygonConnection& right)
{
    return _z < right._z;
}
