#ifndef WINDOW_H
#define WINDOW_H

#include "windowimpl.h"
#include "../mainscene.h"

class Window
{
public:
    Window(WindowImpl *p) : p(p) {}
    virtual ~Window()
    {
        delete p;
    }

    void show()
    {
        p->show();
    }

    void setBaseClass(BaseClass &baseClass)
    {
        p->setBaseClass(baseClass);
    }

private:
    WindowImpl *p = nullptr;
};

#endif // WINDOW_H
