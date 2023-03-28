#include "rotatecommand.h"


RotateCommand::RotateCommand(BaseClass &baseClass, Axis axe, double angle)
    : Command(baseClass), _angle(angle), _axe(axe)
{

}


RotateCommand::RotateCommand(BaseClass &baseClass, Axis axe, double angle,
                             ObjectIterator &start, ObjectIterator &end)
    : Command(baseClass, start, end), _angle(angle), _axe(axe)
{

}


RotateCommand::RotateCommand(BaseClass &baseClass, Axis axe, double angle,
                             ObjectIterator &start)
    : Command(baseClass, start), _angle(angle), _axe(axe)
{

}


void RotateCommand::execute()
{
    _baseClass.getRotateManager().setAxe(_axe);
    _baseClass.getRotateManager().setAngle(_angle);

    if (customIterator)
    {
        _baseClass.getRotateManager().apply(_start, _end);
    }
    else
    {
        _baseClass.getRotateManager().apply(_baseClass.getMainScene().begin(),
                                            _baseClass.getMainScene().end());
    }
}
