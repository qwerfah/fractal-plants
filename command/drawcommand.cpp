#include "drawcommand.h"


DrawCommand::DrawCommand(BaseClass &baseClass)
    : Command(baseClass)
{

}


DrawCommand::DrawCommand(BaseClass &baseClass, ObjectIterator &start, ObjectIterator &end)
    : Command(baseClass, start, end)
{

}


DrawCommand::DrawCommand(BaseClass &baseClass, ObjectIterator &start)
    : Command(baseClass, start)
{

}


void DrawCommand::execute()
{
    _baseClass.getDrawManager().clear();
    _baseClass.getDrawManager().apply(_baseClass.getMainScene().begin(),
                                     _baseClass.getMainScene().end(),
                                     _baseClass.getMainScene().posBegin());
}
