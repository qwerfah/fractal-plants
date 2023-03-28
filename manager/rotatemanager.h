#ifndef ROTATEMANAGER_H
#define ROTATEMANAGER_H


#include "transformmanager.h"
#include "enums.h"


class RotateManager : TransformManager
{
public:
    RotateManager();

    virtual size_t apply(const ObjectIterator& start,
                         const ObjectIterator& end) override;

    void setAngle(double angle);
    void setAxe(Axis axe);

private:
    double _angle;
    Axis _axe;
};

#endif // ROTATEMANAGER_H
