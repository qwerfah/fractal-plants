#ifndef GENERATEMANAGER_H
#define GENERATEMANAGER_H


#include "manager.h"
#include <QString>
#include "enums.h"
#include "generator/generateoptions.h"


class GenerateManager : Manager
{
public:
    GenerateManager();

    void generate(Generators id, GenerateOptions* options,
                  const ObjectIterator &index);
};


#endif // GENERATEMANAGER_H
