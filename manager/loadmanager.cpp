#include "loadmanager.h"
#include "loader/fileloader.h"

LoadManager::LoadManager()
{

}

void LoadManager::loadFromFile(const std::string &file, const ObjectIterator &index)
{
    FileLoader loader(file);

    std::shared_ptr<TransformableObject> object = loader.load();
    *index = object;
}

void LoadManager::loadFromFile(const char *file, const ObjectIterator &index)
{
    loadFromFile(std::string(file), index);
}

void LoadManager::loadFromFile(const QString &file, const ObjectIterator &index)
{
    loadFromFile(file.toStdString(), index);
}
