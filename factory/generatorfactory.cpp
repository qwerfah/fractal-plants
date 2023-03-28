#include "generatorfactory.h"
#include "generator/fractalplantgenerator.h"

Generator* GeneratorFactory::get(Generators id)
{
    switch (id) {
    case FRACTALPLANTGENERATOR:
        return new FractalPlantGenerator;
    default:
        throw FactoryWrongValue("Builder factory. Requested wrong value", id);
    }
}
