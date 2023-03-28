#include "builderfactory.h"
#include "builder/fractalplantbuilder.h"
#include "builder/psurfacebuilder.h"

Builder* BuilderFactory::get(Builders id)
{
    switch (id)
    {
    case FRACTALPLANTBUILDER:
        return new FractalPlantBuilder();
    case PSURFACEBUILDER:
        return new PSurfaceBuilder();
    default:
        throw FactoryWrongValue("Builder factory. Requested wrong value", id);
    }
}
