#include "transformableobjectfactory.h"
#include "transformableobject/fractalplantcarcass.h"
#include "transformableobject/polygonsurface.h"
#include "transformableobject/compositeobject.h"

TransformableObject* TransformableObjectFactory::get(TransformableObjects id)
{
    switch (id)
    {
    case FRACTALPLANTCARCASS:
        return new FractalPlantCarcass;
    case POLYGONSURFACE:
        return new PolygonSurface;
    case COMPOSITEOBJECT:
        return new CompositeObject;
    default:
        throw FactoryWrongValue("Transformable object factory. Requested wrong value", id);
    }
}
