#include "generatemanager.h"
#include "builder/fractalplantbuilder.h"
#include "generator/fractalplantgenerator.h"
#include "factory/generatorfactory.h"

GenerateManager::GenerateManager()
{
}

void GenerateManager::generate(Generators id, GenerateOptions* options,
                               const ObjectIterator &index)
{ 
    GeneratorFactory factory;
    Generator* generator = factory.get(id);
    generator->setOptions(options);
    std::shared_ptr<TransformableObject> object = generator->generate();
    *index = object;
}
