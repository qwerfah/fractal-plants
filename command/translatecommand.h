#ifndef TRANSLATECOMMAND_H
#define TRANSLATECOMMAND_H


#include "command.h"


class TranslateCommand : public Command
{
public:
    TranslateCommand(BaseClass &baseClass, double x, double y, double z);
    TranslateCommand(BaseClass &baseClass, double x, double y, double z, ObjectIterator &start, ObjectIterator &end);
    TranslateCommand(BaseClass &baseClass, double x, double y, double z, ObjectIterator &start);
    void execute();

private:
    const double _x;
    const double _y;
    const double _z;
};


#endif // TRANSLATECOMMAND_H
