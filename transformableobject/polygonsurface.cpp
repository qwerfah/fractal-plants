#include "polygonsurface.h"
#include "transform/polygonsurfacetransformation.h"
#include "sort.h"
#include "draw/drawscene.h"
#include "light/pointlight.h"
#include <QPainter>
#include <cmath>

PolygonSurface::PolygonSurface()
{
    transformation = std::shared_ptr<Transformation>(new PolygonSurfaceTransformation);
}

void PolygonSurface::translate(double x, double y, double z)
{
    transformation->translate(this, x, y, z);
}

void PolygonSurface::placeToCenter()
{
    // Place in screen center
    double avgX = 0, avgY = 0, avgZ = 0;
    for (auto &point : points)
    {
        avgX += point.x();
        avgY += point.y();
        avgZ += point.z();
    }

    avgX /= points.size();
    avgY /= points.size();
    avgZ /= points.size();
    this->translate(-avgX + HALF_WIDTH, -avgY + HALF_WIDTH, -avgZ);
}

bool PolygonSurface::operator<(const TransformableObject& other)
{
    const PolygonSurface& polygon = static_cast<const PolygonSurface&>(other);

    return z < polygon.z;
}

TransformableObject& PolygonSurface::operator=(const TransformableObject& other)
{
    const PolygonSurface& surface = static_cast<const PolygonSurface&>(other);

    points = surface.points;
    connections = surface.connections;
    transformation = surface.transformation;
    z = surface.z;
    fillColor = surface.fillColor;
    boarderColor = surface.boarderColor;
    _id = surface._id;

    return *this;
}

void PolygonSurface::scale(double kx, double ky, double kz)
{
    transformation->scale(this, kx, ky, kz);
}

void PolygonSurface::rotateX(double angle)
{
    transformation->rotateX(this, angle);
}

void PolygonSurface::rotateY(double angle)
{
    transformation->rotateY(this, angle);
}

void PolygonSurface::rotateZ(double angle)
{
    transformation->rotateZ(this, angle);
}

void PolygonSurface::push(const Point3d &point)
{
    points.push_back(point);
}

void PolygonSurface::push(const PolygonConnection &connection)
{
    connections.push_back(connection);
}

void PolygonSurface::draw(DrawScene &scene, std::shared_ptr<Projection> &projection,
                          const Position &pos)
{
    QColor clr = scene.getPen().color();
    QColor fclr = scene.getBrush().color();

    placeToCenter();
    prepareVisualization();

    Sort<PolygonConnection>::sort(connections);

    for (auto &connection : connections)
    {
        std::vector<int> penColor(3, 0);
        std::vector<int> brushColor(3, 0);

        penColor[0] = boarderColor.red();
        penColor[1] = boarderColor.green();
        penColor[2] = boarderColor.blue();
        brushColor[0] = fillColor.red();
        brushColor[1] = fillColor.green();
        brushColor[2] = fillColor.blue();

        size_t s = connection.size();
        std::vector<Point2d> polygon;
        for (size_t i = 0; i < s; i++)
        {
            Point3d p3d = points[connection[i]];
            polygon.push_back(projection->project(p3d));
        }

        double I;

        switch (scene.getLight()->getType())
        {
        case POINT:
        {
            Point3d rv = static_cast<PointLight*>(scene.getLight())->getPosition() - connection.center();
            I = ABSORPTION * (rv.x() * connection.normal().x() + rv.y() *
                              connection.normal().y() + rv.z() * connection.normal().z()) /
                    sqrt((rv.x() * rv.x() + rv.y() * rv.y() + rv.z() * rv.z()) *
                         (connection.normal().x() * connection.normal().x() + connection.normal().y() *
                          connection.normal().y() + connection.normal().z() * connection.normal().z()));
            I = DIFFUSED_LIGHT * 255 + fabs(255 * I);

            if(I > 255)
            {
                I = 255;
            }
            if(isnanf(I))
            {
                I = 0;
            }

            for (uint i = 0; i < 3; i++)
            {
                penColor[i] = I - penColor[i];
                if (penColor[i] < 0)
                {
                    penColor[i] = 0;
                }

                brushColor[i] = I - brushColor[i];
                if (brushColor[i] < 0)
                {
                    brushColor[i] = 0;
                }
            }
            break;
        }

        case DIFFUSED:
            break;
        }

        scene.setColor(QColor(penColor[0], penColor[1], penColor[2]));
        scene.setFillColor(QColor(brushColor[0], brushColor[1], brushColor[2]));

        scene.addPolygon(polygon);
    }

    scene.setColor(clr);
    scene.setFillColor(fclr);
}

void PolygonSurface::prepareVisualization()
{
    for (auto &connection : connections)
    {
        double x = 0, y = 0, z = 0;
        for (size_t i = 0; i < connection.size(); i++)
        {
            x += points[connection[i]].x();
            y += points[connection[i]].y();
            z += points[connection[i]].z();
        }
        x /= connection.size();
        y /= connection.size();
        z /= connection.size();
        connection.z() = z;
        connection.center() = Point3d(x, y, z);

        connection.normal().setX((points[connection[1]].y() - points[connection[0]].y()) *
                (points[connection[2]].z() - points[connection[0]].z()) -
                                 (points[connection[1]].z() - points[connection[0]].z()) *
                (points[connection[2]].y() - points[connection[0]].y()));
        connection.normal().setY((points[connection[1]].z() - points[connection[0]].z()) *
                (points[connection[2]].x() - points[connection[0]].x()) -
                                 (points[connection[1]].x() - points[connection[0]].x()) *
                (points[connection[2]].z() - points[connection[0]].z()));
        connection.normal().setZ((points[connection[1]].x() - points[connection[0]].x()) *
                (points[connection[2]].y() - points[connection[0]].y()) -
                                 (points[connection[1]].y() - points[connection[0]].y()) *
                (points[connection[2]].x() - points[connection[0]].x()));
    }
}

void PolygonSurface::setPoints(const std::vector<Point3d> &pts)
{
    points = pts;
}

void PolygonSurface::setConnections(const std::vector<PolygonConnection> &cns)
{
    connections = cns;
}

void PolygonSurface::setFillColor(QColor color)
{
    fillColor = color;
}

void PolygonSurface::setBoarderColor(QColor color)
{
    boarderColor = color;
}

std::vector<Point3d> &PolygonSurface::getPoints()
{
    return points;
}

std::vector<PolygonConnection> &PolygonSurface::getConnections()
{
    return connections;
}

QColor PolygonSurface::getFillColor() const
{
    return fillColor;
}

QColor PolygonSurface::getBoarderColor() const
{
    return boarderColor;
}

double PolygonSurface::getDepth(double x, double y)
{
    double depth = 0;

    return depth;
}
