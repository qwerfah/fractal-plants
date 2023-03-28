#include "mainscene.h"

MainScene::MainScene()
{
}

ObjectIterator MainScene::begin()
{
    return objects.begin();
}

ObjectIterator MainScene::end()
{
    return objects.end();
}

std::vector<Position>::iterator MainScene::posBegin()
{
    return positions.begin();
}

std::vector<Position>::iterator MainScene::posEnd()
{
    return positions.end();
}

void MainScene::push(std::shared_ptr<TransformableObject>& obj)
{
    objects.push_back(obj);
    positions.push_back(Position());
}

void MainScene::grow()
{
    objects.push_back(std::shared_ptr<TransformableObject>(nullptr));
    positions.push_back(Position());
}

void MainScene::shrink()
{
    objects.pop_back();
    positions.pop_back();
}
