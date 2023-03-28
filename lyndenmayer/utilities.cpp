#include "utilities.h"
#include "../exceptions.h"
#include <windows.h>
#include <string>

// Split string
std::vector<std::string> split(const std::string& string, char symbol)
{
    std::vector<std::string> names;
    std::string str = string + symbol;
    std::string buf;

    for (size_t i = 0; i < str.length(); ++i)
    {
        if (str[i] != symbol)
        {
            buf += str[i];
        }
        else
        {
            names.push_back(buf);
            buf.clear();
        }
    }

    return names;
}

// Delete spaces from string
std::string removeSpaces(const std::string& str)
{
    std::string res;

    for (auto symbol : str)
    {
        if (symbol != ' ')
        {
            res += symbol;
        }
    }

    return res;
}

// Build and execute function with the specified arguments
// The function code is placed in return (only logical and arithmetic expressions are executed)
int generateFunction(const std::vector<std::string>& names,
                     const std::vector<std::string>& values,
                     std::string code)
{
    if (!values.size() || !code.length() || values.size() != names.size())
    {
        throw BadParameters("Wrong parameters number");
    }

    FILE *f = fopen("code.c", "w");
    if (!f)
    {
        throw BadStream("Stream damaged or not opened");
    }

    fprintf(f, "int func(");
    for (size_t i = 0; i < values.size(); ++i)
    {
        fprintf(f, " double %s", names[i].c_str());
        if (i < values.size() - 1)
        {
            fprintf(f, ",");
        }
    }
    fprintf(f, ")\n{\n");
    fprintf(f, "    return %s;\n", code.c_str());
    fprintf(f, "}");
    fclose(f);

    system("gcc -std=c99 -Wall -Werror -c code.c");
    system("gcc -shared code.o -Wl,--subsystem,windows -o code.dll");

    HMODULE hlib = LoadLibrary(L"code.dll");
    if (!hlib)
    {
        throw BadDLLLibrary("Library damaged or not exists");
    }

    int res = 0;
    try
    {
        if (values.size() == 1)
        {
            typedef int (__cdecl *func)(double);
            func fn;

            fn = (func)GetProcAddress(hlib, "func");
            if (!fn)
            {
                throw BadFunction("Function not exists");
            }
            res = fn(stod(values[0]));
        }
        else if (values.size() == 2)
        {
            typedef int (__cdecl *func)(double, double);
            func fn;

            fn = (func)GetProcAddress(hlib, "func");
            if (!fn)
            {
                throw BadFunction("Function not exists");
            }
            res = fn(stod(values[0]), stod(values[1]));
        }
        else if (values.size() == 3)
        {
            typedef int (__cdecl *func)(double, double, double);
            func fn;

            fn = (func)GetProcAddress(hlib, "func");
            if (!fn)
            {
                throw BadFunction("Function not exists");
            }
            res = fn(stod(values[0]), stod(values[1]), stod(values[2]));
        }
        else if (values.size() == 4)
        {
            typedef int (__cdecl *func)(double, double, double, double);
            func fn;

            fn = (func)GetProcAddress(hlib, "func");
            if (!fn)
            {
                throw BadFunction("Function not exists");
            }
            res = fn(stod(values[0]), stod(values[1]), stod(values[2]), stod(values[3]));
        }
    }
    catch(BadFunction& exception)
    {
        std::cout << exception.what();
        FreeLibrary(hlib);
        throw exception;
    }
    FreeLibrary(hlib);

    return res;
}
