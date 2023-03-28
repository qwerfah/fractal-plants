#include "scalemanager.h"


ScaleManager::ScaleManager() : _x(1), _y(1), _z(1)
{

}


size_t ScaleManager::apply(const ObjectIterator &start,
                           const ObjectIterator &end)
{
    size_t counter = 0;
    for (auto i = start; i < end; ++i)
    {
        auto casted = std::dynamic_pointer_cast<TransformableObject>(*i);
        if (casted)
        {
            casted->scale(_x, _y, _z);
            ++counter;
        }
    }
    return counter;
}


void ScaleManager::setX(double x)
{
    _x = x;
}


void ScaleManager::setY(double y)
{
    _y = y;
}


void ScaleManager::setZ(double z)
{
    _z = z;
}
