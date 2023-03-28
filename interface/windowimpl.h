#ifndef WINDOWIMPLEMENTATION_H
#define WINDOWIMPLEMENTATION_H

#include <memory>
#include "baseclass.h"

class WindowImpl
{
public:
    virtual ~WindowImpl() {}
    virtual void show() = 0;
    virtual void setBaseClass(BaseClass &baseClass) = 0;
};

#endif // WINDOWIMPLEMENTATION_H
