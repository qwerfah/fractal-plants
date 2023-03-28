#ifndef TRANSFORMABLEOBJECT_H
#define TRANSFORMABLEOBJECT_H

#include "geometry/edge2d.h"
#include <QGraphicsScene>
#include <memory>

class DrawScene;

class TransformableObject
{
public:
    TransformableObject() = default;
    virtual ~TransformableObject() = default;

    void setId(const QString& id)
    {
        _id = id.toStdString();
    }

    void setId(const std::string& id)
    {
        _id = id;
    }

    void setId(const char* id)
    {
        _id = std::string(id);
    }

    const std::string &getId() const
    {
        return _id;
    }

    virtual void push(std::shared_ptr<TransformableObject> &obj)
    {
        (void)obj;
    }

    virtual void remove(const std::string& objectId)
    {
        (void)objectId;
    }

    virtual void remove(const QString& objectId)
    {
        (void)objectId;
    }

    virtual void remove(const char* objectId)
    {
        (void)objectId;
    }

    virtual TransformableObject* getComposite()
    {
        return nullptr;
    }

    virtual void rotateX(double angle) = 0;
    virtual void rotateY(double angle) = 0;
    virtual void rotateZ(double angle) = 0;

    virtual void scale(double kx, double ky, double kz) = 0;
    virtual void translate(double x, double y, double z) = 0;
    virtual void placeToCenter() {}
    virtual double getDepth(double x, double y) = 0;
    virtual void draw(DrawScene& scene,
                      std::shared_ptr<Projection>& projection,
                      const Position &pos) = 0;

    virtual bool operator<(const TransformableObject& other) = 0;
    virtual TransformableObject& operator=(const TransformableObject& other) = 0;

protected:
    std::string _id;
};

typedef std::vector<std::shared_ptr<TransformableObject>>::iterator ObjectIterator;

#endif // TRANSFORMABLEOBJECT_H
