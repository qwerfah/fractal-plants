#ifndef LOADMANAGER_H
#define LOADMANAGER_H

#include "manager.h"
#include <QString>

class LoadManager : Manager
{
public:
    LoadManager();

    void loadFromFile(const QString &file, const ObjectIterator &index);
    void loadFromFile(const std::string &file, const ObjectIterator &index);
    void loadFromFile(const char *file, const ObjectIterator &index);
};


#endif // LOADMANAGER_H
