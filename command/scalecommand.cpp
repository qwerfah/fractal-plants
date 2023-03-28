#include "scalecommand.h"


ScaleCommand::ScaleCommand(BaseClass &baseClass, double kx, double ky, double kz)
    : Command(baseClass), _kx(kx), _ky(ky), _kz(kz)
{

}


ScaleCommand::ScaleCommand(BaseClass &baseClass, double kx, double ky, double kz,
    ObjectIterator &start, ObjectIterator &end)
    : Command(baseClass, start, end), _kx(kx), _ky(ky), _kz(kz)
{

}


ScaleCommand::ScaleCommand(BaseClass &baseClass, double kx, double ky, double kz,
                           ObjectIterator &start)
    : Command(baseClass, start), _kx(kx), _ky(ky), _kz(kz)
{

}


void ScaleCommand::execute()
{
    _baseClass.getScaleManager().setX(_kx);
    _baseClass.getScaleManager().setY(_ky);
    _baseClass.getScaleManager().setZ(_kz);

    if (customIterator)
    {
        _baseClass.getScaleManager().apply(_start, _end);
    }
    else
    {
        _baseClass.getScaleManager().apply(_baseClass.getMainScene().begin(),
                                           _baseClass.getMainScene().end());
    }
}
