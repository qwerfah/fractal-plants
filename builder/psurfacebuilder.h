#ifndef PSURFACEBUILDER_H
#define PSURFACEBUILDER_H

#include "builder.h"
#include "auxiliarystructures/polygonconnection.h"

class PSurfaceBuilder : public Builder
{
public:
    PSurfaceBuilder() = default;
    ~PSurfaceBuilder() = default;

    virtual void push(const GeometryPrimitive& primitive) override;
    virtual void push(const AuxiliaryStructure& structure) override;
    virtual void push(const std::shared_ptr<TransformableObject>& object) override;

    void setBoarderColor(QColor color);
    void setFillColor(QColor color);

    virtual std::shared_ptr<TransformableObject> build() override;

private:
    std::vector<Point3d> points;
    std::vector<PolygonConnection> connections;
    QColor boarderColor;
    QColor fillColor;
};

#endif // PSURFACEBUILDER_H
