#include "translatecommand.h"


TranslateCommand::TranslateCommand(BaseClass& baseClass, double x, double y, double z)
    : Command(baseClass), _x(x), _y(y), _z(z)
{
}

TranslateCommand::TranslateCommand(BaseClass& baseClass, double x, double y, double z,
                                   ObjectIterator &start, ObjectIterator &end)
    : Command(baseClass, start, end), _x(x), _y(y), _z(z)
{
}

TranslateCommand::TranslateCommand(BaseClass& baseClass, double x, double y, double z,
                                   ObjectIterator &start)
    : Command(baseClass, start), _x(x), _y(y), _z(z)
{
}

void TranslateCommand::execute()
{
    _baseClass.getTranslateManager().setX(_x);
    _baseClass.getTranslateManager().setY(_y);
    _baseClass.getTranslateManager().setZ(_z);
    if (customIterator)
    {
        _baseClass.getTranslateManager().apply(_start, _end);
    }
    else
    {
        _baseClass.getTranslateManager().apply(_baseClass.getMainScene().begin(),
                                               _baseClass.getMainScene().end());
    }
}
