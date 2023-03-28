#include "drawmanager.h"


DrawManager::DrawManager()
{
    _projection = std::shared_ptr<Projection>(new ParallelProjection);
    _scene = DrawScene();
}


size_t DrawManager::apply(const ObjectIterator& start,
                          const ObjectIterator& end,
                          const std::vector<Position>::iterator& pStart)
{
    size_t counter = 0;
    auto posIterator = pStart;
    for (auto i = start; i < end; ++i)
    {
        auto casted = std::dynamic_pointer_cast<TransformableObject>(*i);
        if (casted)
        {
            casted->draw(_scene, _projection, *posIterator);
            ++counter;
        }
        ++posIterator;
    }
    return counter;
}


void DrawManager::setScene(DrawScene& scene)
{
    _scene = scene;
}


void DrawManager::clear()
{
    _scene.clear();
}


DrawScene& DrawManager::getScene()
{
    return _scene;
}
