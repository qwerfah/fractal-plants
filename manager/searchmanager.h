#ifndef SEARCHMANAGER_H
#define SEARCHMANAGER_H

#include "manager.h"
#include "exceptions.h"
#include "transformableobject/transformableobject.h"


class SearchManager : public Manager
{
  public:
    SearchManager();

    ObjectIterator getById(ObjectIterator& begin, ObjectIterator& end, const QString &id);
    ObjectIterator getById(ObjectIterator& begin, ObjectIterator& end, const std::string &id);
    ObjectIterator getById(ObjectIterator& begin, ObjectIterator& end, const char *id);
};

#endif // SEARCHMANAGER_H
