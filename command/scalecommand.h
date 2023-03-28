#ifndef SCALECOMMAND_H
#define SCALECOMMAND_H


#include "command.h"


class ScaleCommand : public Command
{
public:
    ScaleCommand(BaseClass &baseClass, double kx, double ky, double kz);
    ScaleCommand(BaseClass &baseClass, double kx, double ky, double kz, ObjectIterator &start, ObjectIterator &end);
    ScaleCommand(BaseClass &baseClass, double kx, double ky, double kz, ObjectIterator &start);
    void execute();

private:
    const double _kx;
    const double _ky;
    const double _kz;
};


#endif // SCALECOMMAND_H
