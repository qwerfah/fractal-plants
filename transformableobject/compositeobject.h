#ifndef COMPOSITEOBJECT_H
#define COMPOSITEOBJECT_H

#include "transformableobject.h"
#include <vector>
#include <memory>

class CompositeObject : public TransformableObject
{
public:
    CompositeObject() = default;
    ~CompositeObject() = default;

    virtual void push(std::shared_ptr<TransformableObject> &obj) override;
    virtual void remove(const std::string& objectId) override;
    virtual void remove(const QString& objectId) override;
    virtual void remove(const char* objectId) override;
    virtual TransformableObject* getComposite() override;

    virtual void rotateX(double angle) override;
    virtual void rotateY(double angle) override;
    virtual void rotateZ(double angle) override;
    virtual void scale(double kx, double ky, double kz) override;
    virtual void translate(double x, double y, double z) override;
    virtual void draw(DrawScene& scene,
                      std::shared_ptr<Projection>& projection,
                      const Position &pos) override;
    virtual double getDepth(double x, double y) override;
    virtual bool operator<(const TransformableObject& other) override;
    virtual TransformableObject& operator=(const TransformableObject& other) override;

private:
    std::vector<std::shared_ptr<TransformableObject>> objects;
};


#endif // COMPOSITEOBJECT_H
