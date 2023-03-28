#ifndef FRACTALPLANTGENERATEOPTIONS_H
#define FRACTALPLANTGENERATEOPTIONS_H

#include "generateoptions.h"
#include "lyndenmayer/rule.h"
#include "geometry/point3d.h"
#include "enums.h"
#include <QColor>

class FractalPlantGenerateOptions : public GenerateOptions
{
public:
    FractalPlantGenerateOptions(unsigned short iterations, const std::vector<Rule>& rules,
                                const std::string& axiom,  const std::string& constants, const Point3d& pos,
                                double angleX, double angleY, double angleZ,
                                const QColor& stemColor, const QColor& leafColor,
                                double tFrom = 5, double tStep = 0,
                                DrawMode mode = CARCASS);
    ~FractalPlantGenerateOptions() = default;

    std::vector<Rule> rules() const;
    std::string axiom() const;
    std::string constants() const;
    unsigned short iterations() const;
    Point3d pos() const;
    double angleX() const;
    double angleY() const;
    double angleZ() const;
    double thickFrom() const;
    double thickStep() const;
    QColor stemColor() const;
    QColor leafColor() const;
    DrawMode mode() const;

private:
    unsigned short _iterations;
    std::vector<Rule> _rules;
    std::string _axiom;
    std::string _constants;
    Point3d _pos;
    double _angleX;
    double _angleY;
    double _angleZ;
    double _thickFrom;
    double _thickStep;
    QColor _stemColor;
    QColor _leafColor;
    DrawMode _mode;
};

#endif // FRACTALPLANTGENERATEOPTIONS_H
