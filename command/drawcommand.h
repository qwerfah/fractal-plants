#ifndef DRAWCOMMAND_H
#define DRAWCOMMAND_H


#include "command.h"


class DrawCommand : public Command
{
  public:
    DrawCommand(BaseClass &baseClass);
    DrawCommand(BaseClass &baseClass, ObjectIterator &start, ObjectIterator &end);
    DrawCommand(BaseClass &baseClass, ObjectIterator &start);
    void execute();
};


#endif // DRAWCOMMAND_H
