#ifndef QTWINDOW_H
#define QTWINDOW_H

#include "widget.h"
#include "windowimpl.h"
#include "mainscene.h"


class QtMainWindow : public WindowImpl
{
public:
    QtMainWindow() {}

    ~QtMainWindow() {}

    void show()
    {
        widget.show();
    }

    void setBaseClass(BaseClass &baseClass)
    {
        widget.setBaseClass(baseClass);
    }

private:
    Widget widget;
};

#endif // QTWINDOW_H
