#ifndef FRACTALPLANTGENERATOR_H
#define FRACTALPLANTGENERATOR_H

#include "generateoptions.h"
#include "fractalplantgenerateoptions.h"
#include "generator.h"
#include "geometry/point3d.h"
#include "enums.h"
#include "lyndenmayer/lindenmayer.h"
#include <cmath>

struct State
{
    State() = default;
    State(const Point3d& pos, double _angleX,
          double _angleY, double _angleZ, double _thick) :
        position(pos), angleX(_angleX * TO_RADIANS),
        angleY(_angleY * TO_RADIANS), angleZ(_angleZ * TO_RADIANS), thick(_thick) {}

    Point3d getDirection() const
    {
        Point3d dir(0, 10, 0);

        dir.rotateX(angleX);
        dir.rotateY(angleY);
        dir.rotateZ(angleZ);

        return position + dir;
    }

    Point3d position = Point3d(0, 0, 0);
    double angleX = 0;
    double angleY = 0;
    double angleZ = 0;
    double thick = 0;
    unsigned i = 0;
};

class FractalPlantGenerator : public Generator
{
public:
    FractalPlantGenerator() = default;
    virtual ~FractalPlantGenerator() = default;

    virtual void setOptions(GenerateOptions* options) override;
    virtual std::shared_ptr<TransformableObject> generate() override;

private:
    std::shared_ptr<FractalPlantGenerateOptions> options;
    Lindenmayer system;
    State state;
    std::vector<State> stack;
};

#endif // FRACTALPLANTGENERATOR_H
