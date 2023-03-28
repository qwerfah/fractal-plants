#include "generatecommand.h"


GenerateCommand::GenerateCommand(BaseClass &baseClass, Generators id, GenerateOptions* options)
    : Command(baseClass), _id(id), _options(options)
{
}


void GenerateCommand::execute()
{
    _baseClass.getMainScene().grow(); // Adding new item to the scene

    try
    {
        _baseClass.getGenerateManager().generate(_id, _options,
                                                 _baseClass.getMainScene().end() - 1); // Adding generated object to main scene
    }
    catch(std::exception& exception) // If something wrong
    {
        _baseClass.getMainScene().shrink();
        throw exception;
    }
}
