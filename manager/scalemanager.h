#ifndef SCALEMANAGER_H
#define SCALEMANAGER_H


#include "transformmanager.h"
#include "enums.h"


class ScaleManager : TransformManager
{
public:
    ScaleManager();

    virtual size_t apply(const ObjectIterator& start,
                         const ObjectIterator& end) override;

    void setX(double x);
    void setY(double y);
    void setZ(double z);

private:
    double _x;
    double _y;
    double _z;
};


#endif // SCALEMANAGER_H
