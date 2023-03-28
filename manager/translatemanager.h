#ifndef TRANSLATEMANAGER_H
#define TRANSLATEMANAGER_H


#include "transformmanager.h"


class TranslateManager : TransformManager
{
public:
    TranslateManager();

    virtual size_t apply(const ObjectIterator &start,
                         const ObjectIterator &end) override;

    void setX(int x);
    void setY(int y);
    void setZ(int z);

private:
    int _x;
    int _y;
    int _z;
};

#endif // TRANSLATEMANAGER_H
