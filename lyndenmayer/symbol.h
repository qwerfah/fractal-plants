#ifndef SYMBOL_H
#define SYMBOL_H

#include <string>
#include <vector>

// Символ, возможно с параметрами (параметрическая грамматика)
class Symbol
{

public:
    Symbol() = default;
    Symbol(const std::string& str, size_t index = std::string::npos);
    bool matches(const Symbol& other) const;
    void setParameters(const std::vector<std::string>& params);

    Symbol& operator =(const Symbol& right);
    operator bool();

    std::vector<std::string> getParameters() const;
    size_t getLength() const;
    std::string getSymbol() const;
    int getArity() const;
    std::string toString() const;

    static std::vector<Symbol> toSymbols(const std::string& str);

private:
    void parse(const std::string& str, size_t index);

    std::string symbol;
    std::vector<std::string> parameters;
    size_t length;

};

#endif // SYMBOL_H
