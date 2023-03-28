#ifndef LOADER_H
#define LOADER_H

#include <QString>
#include "transformableobject/transformableobject.h"

class Loader
{
public:
    Loader() = default;
    virtual ~Loader() = default;

    virtual std::shared_ptr<TransformableObject> load() = 0;
};


#endif // LOADER_H
