#include "translatemanager.h"


TranslateManager::TranslateManager() : _x(0), _y(0), _z(0)
{

}

size_t TranslateManager::apply(const ObjectIterator &start,
                               const ObjectIterator &end)
{
    size_t counter = 0;
    for (auto i = start; i < end; ++i)
    {
        auto casted = std::dynamic_pointer_cast<TransformableObject>(*i);
        if (casted)
        {
            casted->translate(_x, _y, _z);
            ++counter;
        }
    }
    return counter;
}


void TranslateManager::setX(int x)
{
    _x = x;
}


void TranslateManager::setY(int y)
{
    _y = y;
}


void TranslateManager::setZ(int z)
{
    _z = z;
}
