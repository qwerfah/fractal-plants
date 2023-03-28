#ifndef COMPOSITEBUILDER_H
#define COMPOSITEBUILDER_H

#include "builder.h"

class CompositeBuilder : public Builder
{
public:
    CompositeBuilder() = default;
    virtual ~CompositeBuilder() = default;

    virtual void push(const GeometryPrimitive& primitive) override;
    virtual void push(const AuxiliaryStructure& structure) override;
    virtual void push(const std::shared_ptr<TransformableObject>& object) override;

    virtual std::shared_ptr<TransformableObject> build() override;

private:
    std::vector<std::shared_ptr<TransformableObject>> objects;
};

#endif // COMPOSITEBUILDER_H
