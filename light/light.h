#ifndef LIGHT_H
#define LIGHT_H

#include "enums.h"

class Light
{
public:
    Light(LightType t) : type(t) {}
    virtual ~Light() = default;

    LightType getType() const
    {
        return type;
    }

protected:
    LightType type;
};

#endif // LIGHT_H
