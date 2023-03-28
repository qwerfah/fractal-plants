#ifndef ROTATECOMMAND_H
#define ROTATECOMMAND_H


#include "enums.h"
#include "command.h"


class RotateCommand : public Command
{
public:
    RotateCommand(BaseClass &baseClass, Axis axe, double angle);
    RotateCommand(BaseClass &baseClass, Axis axe, double angle, ObjectIterator &start, ObjectIterator &end);
    RotateCommand(BaseClass &baseClass, Axis axe, double angle, ObjectIterator &start);
    void execute();

private:
    const double _angle;
    const Axis _axe;
};


#endif // ROTATECOMMAND_H
