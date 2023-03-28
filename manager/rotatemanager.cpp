#include "rotatemanager.h"

RotateManager::RotateManager() : _angle(0), _axe(X)
{
}

size_t RotateManager::apply(const ObjectIterator& start,
                            const ObjectIterator& end)
{
    size_t counter = 0;

    for (auto i = start; i < end; ++i)
    {
        auto casted = std::dynamic_pointer_cast<TransformableObject>(*i);
        if (casted)
        {
            switch (_axe)
            {
            case X:
                casted->rotateX(_angle);
                break;

            case Y:
                casted->rotateY(_angle);
                break;

            case Z:
                casted->rotateZ(_angle);
                break;
            }
            ++counter;
        }
    }

    return counter;
}

void RotateManager::setAngle(double angle)
{
    _angle = angle;
}

void RotateManager::setAxe(Axis axe)
{
    _axe = axe;
}
