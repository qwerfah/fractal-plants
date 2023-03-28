#include "command.h"

Command::Command(BaseClass &baseClass)
    : _baseClass(baseClass)
{

}

Command::~Command()
{

}

Command::Command(BaseClass &baseClass, ObjectIterator &start, ObjectIterator &end)
    : _baseClass(baseClass), _start(start), _end(end), customIterator(true)
{

}

Command::Command(BaseClass &baseClass, ObjectIterator &start)
    : _baseClass(baseClass), _start(start)
{
    auto end = start + 1;
    _end = end;
}
