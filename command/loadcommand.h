#ifndef LOADCOMMAND_H
#define LOADCOMMAND_H


#include "command.h"
#include <QString>

class LoadCommand : public Command
{
public:
    LoadCommand(BaseClass &baseClass, const QString &filename);
    void execute();

private:
    const QString _filename;
};

#endif // LOADCOMMAND_H
