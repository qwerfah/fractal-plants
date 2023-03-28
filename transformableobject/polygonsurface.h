#ifndef POLYGONSURFACE_H
#define POLYGONSURFACE_H

#include "transformableobject.h"
#include "auxiliarystructures/polygonconnection.h"
#include "transform/transformations.h"

class PolygonSurface : public TransformableObject
{
public:
    PolygonSurface();
    ~PolygonSurface() = default;

    virtual void translate(double x, double y, double z) override;
    virtual void placeToCenter() override;
    virtual void scale(double kx, double ky, double kz) override;

    virtual void rotateX(double angle) override;
    virtual void rotateY(double angle) override;
    virtual void rotateZ(double angle) override;

    void push(const Point3d &point);
    void push(const PolygonConnection& connection);
    virtual void draw(DrawScene& scene,
                      std::shared_ptr<Projection>& projection,
                      const Position& pos) override;

    virtual bool operator<(const TransformableObject& other) override;
    virtual TransformableObject& operator=(const TransformableObject& other) override;

    void setPoints(const std::vector<Point3d>& pts);
    void setConnections(const std::vector<PolygonConnection>& cns);
    void setFillColor(QColor color);
    void setBoarderColor(QColor color);
    std::vector<Point3d>& getPoints();
    std::vector<PolygonConnection>& getConnections();
    QColor getFillColor() const;
    QColor getBoarderColor() const;
    virtual double getDepth(double x, double y) override;

private:
    std::vector<Point3d> points;
    std::vector<PolygonConnection> connections;
    std::shared_ptr<Transformation> transformation;
    QColor fillColor;
    QColor boarderColor;
    double z;

    void prepareVisualization();

};

#endif // POLYGONSURFACE_H
