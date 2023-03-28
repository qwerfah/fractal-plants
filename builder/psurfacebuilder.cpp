#include "psurfacebuilder.h"
#include "transformableobject/polygonsurface.h"
#include "factory/transformableobjectfactory.h"
#include <QDebug>

void PSurfaceBuilder::push(const GeometryPrimitive& primitive)
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

void PSurfaceBuilder::push(const AuxiliaryStructure& structure)
{
    try
    {
        const PolygonConnection& connection = static_cast<const PolygonConnection&>(structure);
        connections.push_back(connection);
    }
    catch (std::bad_cast &exception)
    {
        qInfo() << exception.what();
    }
}

void PSurfaceBuilder::push(const std::shared_ptr<TransformableObject>& object)
{
    (void)object;
}

void PSurfaceBuilder::setBoarderColor(QColor color)
{
    boarderColor = color;
}

void PSurfaceBuilder::setFillColor(QColor color)
{
    fillColor = color;
}

std::shared_ptr<TransformableObject> PSurfaceBuilder::build()
{
    PolygonSurface* surface =
            static_cast<PolygonSurface*>(TransformableObjectFactory::get(POLYGONSURFACE));
    surface->setPoints(points);
    surface->setConnections(connections);
    surface->setBoarderColor(boarderColor);
    surface->setFillColor(fillColor);
    surface->placeToCenter();
    return std::shared_ptr<TransformableObject>(surface);
}
