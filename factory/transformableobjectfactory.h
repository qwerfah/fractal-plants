#ifndef TRANSFORMABLEOBJECTFACTORY_H
#define TRANSFORMABLEOBJECTFACTORY_H

#include "factory.h"
#include "transformableobject/transformableobject.h"
#include "enums.h"

class TransformableObjectFactory: public Factory
{
public:
    static TransformableObject* get(TransformableObjects id);

};

#endif // TRANSFORMABLEOBJECTFACTORY_H
