#ifndef POLYGONCONNECTION_H
#define POLYGONCONNECTION_H

#include "auxiliarystructure.h"
#include "geometry/point3d.h"
#include <vector>

class PolygonConnection : public AuxiliaryStructure
{
public:
    PolygonConnection();

    void push(size_t vertex);
    size_t operator[](size_t index);
    void clear();
    size_t size() const;

    Point3d& center();
    Point3d& normal();
    double& z();

    bool operator<(const PolygonConnection& right);

private:
    // Indices of vertices
    std::vector<size_t> vertices;
    // Auxiliary geometric characteristics
    Point3d _center;
    Point3d _normal;
    // Minimum z value to sort on rendering
    double _z;

};

#endif // POLYGONCONNECTION_H
