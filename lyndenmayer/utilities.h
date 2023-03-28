#ifndef UTILITIES_H
#define UTILITIES_H

#include <vector>
#include <string>

std::vector<std::string> split(const std::string& str, char symbol);
std::string removeSpaces(const std::string& str);
int generateFunction(const std::vector<std::string>& names,
                     const std::vector<std::string>& values,
                     std::string code);

#endif // UTILITIES_H
