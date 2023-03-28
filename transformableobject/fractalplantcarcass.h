#ifndef FRACTALPLANT_H
#define FRACTALPLANT_H

#include "transformableobject.h"
#include "auxiliarystructures/connection.h"
#include "transform/transformations.h"
#include "enums.h"

class FractalPlantCarcass : public TransformableObject
{
public:
    FractalPlantCarcass();
    virtual ~FractalPlantCarcass() = default;

    virtual void translate(double x, double y, double z) override;
    virtual void placeToCenter() override;
    virtual void scale(double kx, double ky, double kz) override;

    virtual void rotateX(double angle) override;
    virtual void rotateY(double angle) override;
    virtual void rotateZ(double angle) override;

    void push(const Point3d &point);
    void push(const Connection& connection);
    void draw(DrawScene& scene,
              std::shared_ptr<Projection>& projection,
              const Position& pos) override;

    virtual bool operator<(const TransformableObject& other) override;
    virtual TransformableObject& operator=(const TransformableObject& other) override;

    void setPoints(const std::vector<Point3d>& pts);
    void setConnections(const std::vector<Connection>& cns);
    std::vector<Point3d>& getPoints();
    std::vector<Connection>& getConnections();
    virtual double getDepth(double x, double y) override;

private:
    std::vector<Point3d> points;
    std::vector<Connection> connections;
    std::shared_ptr<Transformation> transformation;
    double _z;
};

#endif // FRACTALPLANT_H
