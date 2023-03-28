#ifndef COMMAND_H
#define COMMAND_H


#include "baseclass.h"


class Command
{
public:
    virtual ~Command();
    virtual void execute() = 0;

protected:
    Command(BaseClass &baseClass);
    Command(BaseClass &baseClass, ObjectIterator &start, ObjectIterator &end);
    Command(BaseClass &baseClass, ObjectIterator &start);
    BaseClass& _baseClass;
    ObjectIterator _start;
    ObjectIterator _end;
    bool customIterator = false;
};


#endif // COMMAND_H
