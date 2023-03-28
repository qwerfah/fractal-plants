#ifndef FRACTALPLANTBUILDER_H
#define FRACTALPLANTBUILDER_H

#include "builder.h"
#include "transformableobject/fractalplantcarcass.h"

class FractalPlantBuilder : public Builder
{
public:
    FractalPlantBuilder() = default;
    virtual ~FractalPlantBuilder() = default;

    virtual void push(const GeometryPrimitive& primitive) override;
    virtual void push(const AuxiliaryStructure& structure) override;
    virtual void push(const std::shared_ptr<TransformableObject>& object) override;

    virtual std::shared_ptr<TransformableObject> build() override;

private:
    std::vector<Point3d> points;
    std::vector<Connection> connections;
};

#endif // FRACTALPLANTBUILDER_H
