#include "fractalplantgenerator.h"
#include "builder/fractalplantbuilder.h"
#include "builder/compositebuilder.h"
#include "transformableobject/polygonsurface.h"
#include "transformableobject/cylinder.h"
#include "loader/fileloader.h"
#include "fractalplantgenerateoptions.h"
#include "exceptions.h"
#include <QDebug>

void FractalPlantGenerator::setOptions(GenerateOptions *_options)
{
    FractalPlantGenerateOptions* foptions = dynamic_cast<FractalPlantGenerateOptions*>(_options);
    if (!foptions)
    {
        throw BadCast("Fractal plant generator: bad dynamic cast.");
    }
    options = std::shared_ptr<FractalPlantGenerateOptions>(foptions);
}

std::shared_ptr<TransformableObject> FractalPlantGenerator::generate()
{
    if (!options)
    {
        throw BadPtr("Fractal plant generator: no options");
    }

    CompositeBuilder cbuilder;
    std::vector<std::shared_ptr<TransformableObject>> objects;
    Cylinder* cylinder;
    std::string constants = "";

    system.setRules(options->rules());
    system.setConstants(options->constants());
    state = State(options->pos(), 90, 0, 90, options->thickFrom());

    std::string rule = system.process(options->axiom(), options->iterations());

    double _angleX = options->angleX() * TO_RADIANS;
    double _angleY = options->angleY() * TO_RADIANS;
    double _angleZ = options->angleZ() * TO_RADIANS;

    int i = 1;
    state.i = 0;

    for (auto symbol : rule)
    {

        switch (symbol)
        {
        case '+':
            state.angleY += _angleY;
            break;

        case '-':
            state.angleY -= _angleY;
            break;

        case '/':
            state.angleZ += _angleZ;
            break;

        case '\\':
            state.angleZ -= _angleZ;
            break;

        case '^':
            state.angleX += _angleX;
            break;

        case '_':
            state.angleX -= _angleX;
            break;

        case '[':
            stack.push_back(state);
            break;

        case ']':
            state = stack.back();
            stack.pop_back();
            if (objects.size())
            {
                cylinder = static_cast<Cylinder*>(objects.back().get());
                cylinder->setColor(options->leafColor());
            }
            break;

        default:
            if (constants.find(symbol) == std::string::npos)
            {
                Point3d curr = state.getDirection();
                objects.push_back(std::shared_ptr<TransformableObject>
                                 (new Cylinder(state.position, curr, state.thick,
                                               state.thick - options->thickStep(),
                                               options->stemColor(), options->mode())));
                state.position = curr;
                state.thick -= options->thickStep();
                state.i = i; i++; // (=^.^=)
            }
            break;
        }
    }

    for (auto object : objects)
    {
        cbuilder.push(object);
    }

    return cbuilder.build();
}
