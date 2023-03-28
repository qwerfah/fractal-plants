#include "loadcommand.h"

LoadCommand::LoadCommand(BaseClass &baseClass, const QString &filename)
    : Command(baseClass), _filename(filename)
{
}

void LoadCommand::execute()
{
    _baseClass.getMainScene().grow();

    try
    {
        _baseClass.getLoadManager().loadFromFile(_filename, _baseClass.getMainScene().end() - 1);
    }
    catch(std::exception& exception)
    {
        _baseClass.getMainScene().shrink();
        throw exception;
    }
}
