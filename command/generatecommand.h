#ifndef GENERATECOMMAND_H
#define GENERATECOMMAND_H


#include "command.h"
#include "generator/generateoptions.h"
#include <QString>


class GenerateCommand : public Command
{
public:
    GenerateCommand(BaseClass &baseClass, Generators id, GenerateOptions* options);
    void execute();

private:
    Generators _id;
    GenerateOptions* _options;
};


#endif // GENERATECOMMAND_H
