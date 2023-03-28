#ifndef GENERATOR_H
#define GENERATOR_H

#include <memory>
#include "transformableobject/transformableobject.h"
#include "generateoptions.h"

class Generator
{
public:
    Generator() = default;
    virtual ~Generator() = default;

    virtual void setOptions(GenerateOptions*) = 0;

    virtual std::shared_ptr<TransformableObject> generate() = 0;
};

#endif // GENERATOR_H
