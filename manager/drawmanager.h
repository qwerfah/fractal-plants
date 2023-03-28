#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H


#include "draw/drawscene.h"
#include "transformableobject/transformableobject.h"
#include "manager.h"
#include "projection/parallelprojection.h"
#include "exceptions.h"


class DrawManager : Manager
{
public:
    DrawManager();

    size_t apply(const ObjectIterator& start,
                 const ObjectIterator& end,
                 const std::vector<Position>::iterator &pStart);

    void setScene(DrawScene &scene);
    void clear();
    DrawScene &getScene();

private:
    DrawScene _scene;
    std::shared_ptr<Projection> _projection;
};


#endif // DRAWMANAGER_H
