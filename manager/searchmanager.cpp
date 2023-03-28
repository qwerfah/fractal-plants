#include "searchmanager.h"


SearchManager::SearchManager()
{

}


ObjectIterator SearchManager::getById(ObjectIterator &begin, ObjectIterator &end, const std::string &id)
{
    auto &i = begin;
    for (; i < end; ++i)
    {
        if (i->get()->getId() == id)
        {
            return i;
        }
    }
    throw NotFound("Figure with name " + id + " not found");
}


ObjectIterator SearchManager::getById(ObjectIterator &begin, ObjectIterator &end, const char *id)
{
    return getById(begin, end, std::string(id));
}


ObjectIterator SearchManager::getById(ObjectIterator &begin, ObjectIterator &end, const QString &id)
{
    return getById(begin, end, id.toStdString());
}
