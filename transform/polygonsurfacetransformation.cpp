#include "polygonsurfacetransformation.h"
#include "transformableobject/polygonsurface.h"

void PolygonSurfaceTransformation::translate(TransformableObject* model, double x,
                                             double y, double z)
{
    auto casted = static_cast<PolygonSurface*>(model);
    std::vector<Point3d> &points = casted->getPoints();

    for (size_t i = 0; i < points.size(); i++)
    {
        points[i].translate(x, y, z);
    }
}

void PolygonSurfaceTransformation::scale(TransformableObject* model, double kx,
                                         double ky, double kz)
{
    auto casted = static_cast<PolygonSurface*>(model);
    std::vector<Point3d> &points = casted->getPoints();

    for (size_t i = 0; i < points.size(); i++)
    {
        points[i].scale(kx, ky, kz);
    }
}

void PolygonSurfaceTransformation::rotateX(TransformableObject* model, double angle)
{
    auto casted = static_cast<PolygonSurface*>(model);
    std::vector<Point3d> &points = casted->getPoints();

    for (size_t i = 0; i < points.size(); i++)
    {
        points[i].rotateX(angle);
    }
}

void PolygonSurfaceTransformation::rotateY(TransformableObject* model, double angle)
{
    auto casted = static_cast<PolygonSurface*>(model);
    std::vector<Point3d> &points = casted->getPoints();

    for (size_t i = 0; i < points.size(); i++)
    {
        points[i].rotateY(angle);
    }
}

void PolygonSurfaceTransformation::rotateZ(TransformableObject* model, double angle)
{
    auto casted = static_cast<PolygonSurface*>(model);
    std::vector<Point3d> &points = casted->getPoints();

    for (size_t i = 0; i < points.size(); i++)
    {
        points[i].rotateZ(angle);
    }
}
