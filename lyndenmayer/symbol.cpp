#include "symbol.h"
#include "utilities.h"

Symbol::Symbol(const std::string& str, size_t index)
{
    if(index != std::string::npos)
    {
        this->parse(str, index);
    }
    else
    {
        this->symbol = str;
        this->length = str.length();
    }
}

Symbol& Symbol::operator =(const Symbol& right)
{
    this->symbol = right.symbol;
    this->parameters = right.parameters;
    this->length = right.length;

    return *this;
}

Symbol::operator bool()
{
    return this->symbol.length();
}

// Split symbol into name and parameters
void Symbol::parse(const std::string& str, size_t index)
{
    size_t startIndex = index;

    this->symbol = str[index];

    if(index + 1 < str.length() && str[index + 1] == '(')
    {
        int scope = 1;
        int start = ++index + 1;

        while(str[++index])
        {
            if(str[index] == '(')
            {
                ++scope;
            }
            else if(str[index] == ')' && --scope == 0)
            {
                break;
            }
        }

        this->parameters = split(str.substr(start, index - start), ',');
    }

    this->length = index - startIndex;
}

// The arity of the symbol
int Symbol::getArity() const
{
    if(!this->parameters.size())
    {
        return 0;
    }
    return this->parameters.size();
}

// Symbol match
bool Symbol::matches(const Symbol& other) const
{
        return (this->symbol == other.symbol &&
                this->getArity() == other.getArity());
}

// Convert to string
std::string Symbol::toString() const
{
    std::string str = this->symbol;

    if(this->parameters.size())
    {
        str += "(";

        for(size_t i = 0; i < this->parameters.size(); ++i)
        {
            if(i == this->parameters.size() - 1)
            {
                str += this->parameters[i] + ")";
            }
            else
            {
                str += this->parameters[i] + ",";
            }
        }
    }

    return str;
}

size_t Symbol::getLength() const
{
    return this->length;
}

std::string Symbol::getSymbol() const
{
    return this->symbol;
}

std::vector<std::string> Symbol::getParameters() const
{
    return this->parameters;
}

void Symbol::setParameters(const std::vector<std::string>& params)
{
    this->parameters = params;
}

// Split string into symbols
std::vector<Symbol> Symbol::toSymbols(const std::string& str)
{
    std::vector<Symbol> symbols;

    for(size_t i = 0; i < str.length(); ++i)
    {
        Symbol symbol(str, i);
        i += symbol.getLength();
        symbols.push_back(symbol);
    }

    return symbols;
}
