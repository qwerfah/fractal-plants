#ifndef MAINSCENE_H
#define MAINSCENE_H


#include "draw/drawscene.h"
#include "transformableobject/transformableobject.h"
#include "manager/drawmanager.h"
#include "manager/rotatemanager.h"
#include "manager/scalemanager.h"
#include "manager/translatemanager.h"
#include "position.h"


class MainScene
{
  public:
    MainScene();

    void push(std::shared_ptr<TransformableObject> &obj);
    void grow();
    void shrink();

    ObjectIterator begin();
    ObjectIterator end();

    std::vector<Position>::iterator posBegin();
    std::vector<Position>::iterator posEnd();

  private:
    std::vector<std::shared_ptr<TransformableObject>> objects;
    std::vector<Position> positions;
};


#endif // MAINSCENE_H
