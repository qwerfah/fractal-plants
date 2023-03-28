#include "fractalplantgenerateoptions.h"

FractalPlantGenerateOptions::FractalPlantGenerateOptions
(unsigned short iterations, const std::vector<Rule>& rules,
 const std::string& axiom, const std::string& constants, const Point3d& pos,
 double angleX, double angleY, double angleZ,
 const QColor& stemColor, const QColor& leafColor,
 double tFrom, double tStep,
 DrawMode mode) :
    _iterations(iterations), _rules(rules), _axiom(axiom), _constants(constants),
    _pos(pos), _angleX(angleX), _angleY(angleY),
    _angleZ(angleZ), _thickFrom(tFrom), _thickStep(tStep),
    _stemColor(stemColor), _leafColor(leafColor), _mode(mode)
{
}

std::vector<Rule> FractalPlantGenerateOptions::rules() const
{
    return _rules;
}

std::string FractalPlantGenerateOptions::axiom() const
{
    return _axiom;
}

std::string FractalPlantGenerateOptions::constants() const
{
    return _constants;
}

unsigned short FractalPlantGenerateOptions::iterations() const
{
    return _iterations;
}

Point3d FractalPlantGenerateOptions::pos() const
{
    return _pos;
}

double FractalPlantGenerateOptions::angleX() const
{
    return _angleX;
}

double FractalPlantGenerateOptions::angleY() const
{
    return _angleY;
}

double FractalPlantGenerateOptions::angleZ() const
{
    return _angleZ;
}

double FractalPlantGenerateOptions::thickFrom() const
{
    return _thickFrom;
}

double FractalPlantGenerateOptions::thickStep() const
{
    return _thickStep;
}

QColor FractalPlantGenerateOptions::stemColor() const
{
    return _stemColor;
}

QColor FractalPlantGenerateOptions::leafColor() const
{
    return _leafColor;
}

DrawMode FractalPlantGenerateOptions::mode() const
{
    return _mode;
}
