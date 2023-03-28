#ifndef TRANSFORMMANAGER_H
#define TRANSFORMMANAGER_H


#include "manager.h"


class TransformManager : Manager
{
public:
    TransformManager() = default;
    virtual ~TransformManager() = default;
    virtual size_t apply(const ObjectIterator& start,
                         const ObjectIterator& end) = 0;
};



#endif // TRANSFORMMANAGER_H
