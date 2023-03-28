#include "fractalplantcarcass.h"
#include "transform/FractalPlantCarcassTransformation.h"
#include "cylinder.h"
#include "loader/fileloader.h"
#include "draw/drawscene.h"

FractalPlantCarcass::FractalPlantCarcass()
{
    transformation = std::shared_ptr<Transformation>(new FractalPlantCarcassTransformation);
}

void FractalPlantCarcass::translate(double x, double y, double z)
{
    transformation->translate(this, x, y, z);
}

void FractalPlantCarcass::placeToCenter()
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

void FractalPlantCarcass::scale(double kx, double ky, double kz)
{
    transformation->scale(this, kx, ky, kz);
}

void FractalPlantCarcass::rotateX(double angle)
{
    transformation->rotateX(this, angle);
}

void FractalPlantCarcass::rotateY(double angle)
{
    transformation->rotateY(this, angle);
}

void FractalPlantCarcass::rotateZ(double angle)
{
    transformation->rotateZ(this, angle);
}

void FractalPlantCarcass::push(const Point3d &point)
{
    points.push_back(point);
}

void FractalPlantCarcass::push(const Connection &connection)
{
    connections.push_back(connection);
}

void FractalPlantCarcass::draw(DrawScene &scene, std::shared_ptr<Projection> &projection,
                         const Position &pos)
{
    placeToCenter();

    for (auto &e : connections)
    {
        Point3d p13d = points[e.getStart()];
        Point3d p23d = points[e.getEnd()];

        p13d.translate(pos.center[0], pos.center[1], pos.center[2]);
        p23d.translate(pos.center[0], pos.center[1], pos.center[2]);

        p13d.rotateX(pos.orientation[0]);
        p23d.rotateX(pos.orientation[0]);

        p13d.rotateY(pos.orientation[1]);
        p23d.rotateY(pos.orientation[1]);

        p13d.rotateZ(pos.orientation[2]);
        p23d.rotateZ(pos.orientation[2]);

        Point2d p1 = projection->project(p13d);
        Point2d p2 = projection->project(p23d);

        Edge2d line = Edge2d(p1, p2);
        scene.addLine(line);
    }
}

bool FractalPlantCarcass::operator<(const TransformableObject& other)
{
    return _z < static_cast<const FractalPlantCarcass&>(other)._z;
}

TransformableObject& FractalPlantCarcass::operator=(const TransformableObject& other)
{
    const FractalPlantCarcass& carcass = static_cast<const FractalPlantCarcass&>(other);

    points = carcass.points;
    connections = carcass.connections;
    _z = carcass._z;
    _id = carcass._id;
    transformation = carcass.transformation;

    return *this;
}

void FractalPlantCarcass::setPoints(const std::vector<Point3d> &pts)
{
    points = pts;
}

void FractalPlantCarcass::setConnections(const std::vector<Connection> &cns)
{
    connections = cns;
}

std::vector<Point3d> &FractalPlantCarcass::getPoints()
{
    return points;
}

std::vector<Connection> &FractalPlantCarcass::getConnections()
{
    return connections;
}

double FractalPlantCarcass::getDepth(double x, double y)
{
    double depth = 0;

    return depth;
}
