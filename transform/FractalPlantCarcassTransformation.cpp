#include "FractalPlantCarcassTransformation.h"
#include "transformableobject/fractalplantcarcass.h"


void FractalPlantCarcassTransformation::translate(TransformableObject* model, double x,
                                      double y, double z)
{
    auto casted = static_cast<FractalPlantCarcass*>(model);
    std::vector<Point3d> &points = casted->getPoints();

    for (size_t i = 0; i < points.size(); i++)
    {
        points[i].translate(x, y, z);
    }
}


void FractalPlantCarcassTransformation::scale(TransformableObject* model, double kx,
                                  double ky, double kz)
{
    auto casted = static_cast<FractalPlantCarcass*>(model);
    std::vector<Point3d> &points = casted->getPoints();

    for (size_t i = 0; i < points.size(); i++)
    {
        points[i].scale(kx, ky, kz);
    }
}


void FractalPlantCarcassTransformation::rotateX(TransformableObject* model, double angle)
{
    auto casted = static_cast<FractalPlantCarcass*>(model);
    std::vector<Point3d> &points = casted->getPoints();

    for (size_t i = 0; i < points.size(); i++)
    {
        points[i].rotateX(angle);
    }
}


void FractalPlantCarcassTransformation::rotateY(TransformableObject* model, double angle)
{
    auto casted = static_cast<FractalPlantCarcass*>(model);
    std::vector<Point3d> &points = casted->getPoints();

    for (size_t i = 0; i < points.size(); i++)
    {
        points[i].rotateY(angle);
    }
}


void FractalPlantCarcassTransformation::rotateZ(TransformableObject* model, double angle)
{
    auto casted = static_cast<FractalPlantCarcass*>(model);
    std::vector<Point3d> &points = casted->getPoints();

    for (size_t i = 0; i < points.size(); i++)
    {
        points[i].rotateZ(angle);
    }
}
