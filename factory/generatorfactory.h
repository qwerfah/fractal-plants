#ifndef GENERATEDOBJECTSFACTORY_H
#define GENERATEDOBJECTSFACTORY_H

#include "factory.h"
#include "generator/generator.h"
#include "enums.h"

class GeneratorFactory : public Factory
{
public:
    static Generator *get(Generators id);
};

#endif // GENERATEDOBJECTSFACTORY_H
