#include "compositebuilder.h"
#include "transformableobject/compositeobject.h"
#include "factory/transformableobjectfactory.h"

void CompositeBuilder::push(const GeometryPrimitive& primitive)
{
    (void)primitive;
}

void CompositeBuilder::push(const AuxiliaryStructure& structure)
{
    (void)structure;
}

void CompositeBuilder::push(const std::shared_ptr<TransformableObject>& object)
{
    objects.push_back(object);
}

std::shared_ptr<TransformableObject> CompositeBuilder::build()
{
    CompositeObject* object =
            static_cast<CompositeObject*>(TransformableObjectFactory::get(COMPOSITEOBJECT));

    for (auto obj : objects)
    {
        object->push(obj);
    }

    return std::shared_ptr<CompositeObject>(object);
}
