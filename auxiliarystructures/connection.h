#ifndef CONNECTION_H
#define CONNECTION_H

#include "exceptions.h"
#include "auxiliarystructure.h"

class Connection : public AuxiliaryStructure
{
public:
    Connection(size_t start = 0, size_t end = 0, double length = 0);

    size_t getStart() const;
    size_t getEnd() const;

    double length() const
    {
        return _length;
    }

    bool operator<(const Connection& right);

private:
    size_t _start;
    size_t _end;
    double _length;
};

#endif // CONNECTION_H
