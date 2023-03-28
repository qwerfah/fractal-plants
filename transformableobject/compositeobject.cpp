#include "compositeobject.h"
#include "manager/searchmanager.h"
#include "sortprotected.h"
#include <QDebug>

void CompositeObject::push(std::shared_ptr<TransformableObject>& obj)
{
    objects.push_back(obj);
}

void CompositeObject::remove(const std::string &objectId)
{
    SearchManager manager;
    try
    {
        ObjectIterator begin = objects.begin();
        ObjectIterator end = objects.end();
        ObjectIterator i = manager.getById(begin, end, objectId);
        objects.erase(i);
    }
    catch (NotFound& e)
    {
        qInfo() << e.what();
    }
}

void CompositeObject::remove(const QString &objectId)
{
    remove(objectId.toStdString());
}

void CompositeObject::remove(const char *objectId)
{
    remove((std::string)objectId);
}

TransformableObject* CompositeObject::getComposite()
{
    return this;
}

void CompositeObject::rotateX(double angle)
{
    for (size_t i = 0; i < objects.size(); i++)
    {
        objects[i]->rotateX(angle);
    }
}

void CompositeObject::rotateY(double angle)
{
    for (size_t i = 0; i < objects.size(); i++)
    {
        objects[i]->rotateY(angle);
    }
}

void CompositeObject::rotateZ(double angle)
{
    for (size_t i = 0; i < objects.size(); i++)
    {
        objects[i]->rotateZ(angle);
    }
}

void CompositeObject::scale(double kx, double ky, double kz)
{
    for (size_t i = 0; i < objects.size(); i++)
    {
        objects[i]->scale(kx, ky, kz);
    }
}

void CompositeObject::translate(double x, double y, double z)
{
    for (size_t i = 0; i < objects.size(); i++)
    {
        objects[i]->translate(x, y, z);
    }
}

#include "cylinder.h"

void CompositeObject::draw(DrawScene& scene,
                  std::shared_ptr<Projection>& projection,
                  const Position &pos)
{
    SortProtected<TransformableObject>::sort(objects);

    for (size_t i = 0; i < objects.size(); i++)
    {
        objects[i]->draw(scene, projection, pos);
    }
}

double CompositeObject::getDepth(double x, double y)
{
    double depth = objects[0]->getDepth(x, y);

    for (uint i = 1; i < objects.size(); i++)
    {
        double d = objects[i]->getDepth(x, y);
        if (d > depth)
        {
            depth = d;
        }
    }

    return depth;
}

bool CompositeObject::operator<(const TransformableObject& other)
{
    (void)other;
    return true;
}

TransformableObject& CompositeObject::operator=(const TransformableObject& other)
{
    const CompositeObject& composite = static_cast<const CompositeObject&>(other);

    objects = composite.objects;
    _id = composite._id;

    return *this;
}
