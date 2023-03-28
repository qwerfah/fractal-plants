#ifndef POSITION_H
#define POSITION_H


#include <vector>


struct Position
{
    std::vector<double> center = std::vector<double>(3, 0);
    std::vector<double> orientation = std::vector<double>(3, 0);
};


#endif // POSITION_H
