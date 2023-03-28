#ifndef BUILDERFACTORY_H
#define BUILDERFACTORY_H


#include "enums.h"
#include "factory.h"
#include "builder/builder.h"


class BuilderFactory : public Factory
{
public:
    static Builder* get(Builders id);
};


#endif // BUILDERFACTORY_H
