#include "connection.h"

Connection::Connection(size_t start, size_t end, double length) : _start(start), _end(end), _length(length)
{
}

size_t Connection::getStart() const
{
    return _start;
}

size_t Connection::getEnd() const
{
    return  _end;
}

bool Connection::operator<(const Connection& right)
{
    return _length < right._length;
}
