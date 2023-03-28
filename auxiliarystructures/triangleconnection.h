#ifndef TRIANGLECONNECTION_H
#define TRIANGLECONNECTION_H

#include "auxiliarystructure.h"
#include "geometry/point3d.h"

class TriangleConnection : public AuxiliaryStructure
{
public:
    TriangleConnection(size_t a = 0, size_t b = 0, size_t c = 0);

    size_t a() const;
    size_t b() const;
    size_t c() const;

    Point3d& center();
    Point3d& normal();
    double& z();

    bool operator<(const TriangleConnection& right);

private:
    // Indices of vertices
    size_t _a;
    size_t _b;
    size_t _c;
    // Auxiliary geometric characteristics
    Point3d _center;
    Point3d _normal;
    // Minimum z value to sort on rendering
    double _z;

};

#endif // TRIANGLECONNECTION_H
