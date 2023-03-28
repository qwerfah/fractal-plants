#include "fractalplantbuilder.h"
#include "factory/transformableobjectfactory.h"
#include <QDebug>

void FractalPlantBuilder::push(const GeometryPrimitive& primitive)
{
    try
    {
        const Point3d& point = static_cast<const Point3d&>(primitive);
        points.push_back(point);
    }
    catch (std::bad_cast &exception)
    {
        qInfo() << exception.what();
    }
}

void FractalPlantBuilder::push(const AuxiliaryStructure& structure)
{
    try
    {
        const Connection& connection = static_cast<const Connection&>(structure);
        connections.push_back(connection);
    }
    catch (std::bad_cast &exception)
    {
        qInfo() << exception.what();
    }
}

void FractalPlantBuilder::push(const std::shared_ptr<TransformableObject>& object)
{
    (void)object;
}

std::shared_ptr<TransformableObject> FractalPlantBuilder::build()
{
    FractalPlantCarcass* plant =
            static_cast<FractalPlantCarcass*>(TransformableObjectFactory::get(FRACTALPLANTCARCASS));
    plant->setPoints(points);
    plant->setConnections(connections);
    return std::shared_ptr<TransformableObject>(plant);
}
