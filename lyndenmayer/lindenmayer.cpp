#include "lindenmayer.h"
#include "utilities.h"
#include <random>
#include <ctime>
#include <QDebug>

Lindenmayer::Lindenmayer()
{
}

void Lindenmayer::setConstants(const std::string& _constants)
{
    this->constants = _constants;
}

void Lindenmayer::setRules(const std::vector<Rule>& _rules)
{
    this->rules = _rules;
}

void Lindenmayer::removeRules()
{
    this->rules.clear();
}

void Lindenmayer::addRule(const std::string& rule)
{
    this->rules.push_back(Rule(rule));
}

std::string Lindenmayer::process(const std::string& _axiom, size_t iterations)
{
    std::vector<Symbol> axiom = this->toSymbols(removeSpaces(_axiom));

    for(size_t i = 0; i < iterations; ++i)
    {
        axiom = this->applyRules(axiom);
    }

    return toString(axiom);
}

std::vector<Symbol> Lindenmayer::toSymbols(const std::string& str)
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

std::vector<Rule> Lindenmayer::getApplicableRules(const Symbol& symbol,
                                                  const Symbol& predecessor,
                                                  const Symbol& successor)
{
    std::vector<Rule> rules;

    for(size_t i = 0; i < this->rules.size(); ++i)
    {
        if(this->rules[i].isApplicable(symbol, predecessor, successor))
        {
            rules.push_back(this->rules[i]);
        }
    }

    return rules;
}

std::vector<Symbol> Lindenmayer::parseSymbol(const Symbol& predecessor,
                                             const Symbol& symbol,
                                             const Symbol& successor)
{
    std::vector<Rule> rules = this->getApplicableRules(symbol, predecessor, successor);

    if(!rules.size())
    {
        return std::vector<Symbol>(1, symbol);
    }

    std::default_random_engine engine{(unsigned long)time(0)};
    std::uniform_int_distribution<int> distr{0, (int)rules.size() - 1};
    return rules[distr(engine)].apply(symbol, predecessor, successor);
}

std::vector<Symbol> Lindenmayer::applyRules(const std::vector<Symbol>& sentence)
{
    std::vector<Symbol> newSentence;

    for(size_t i = 0; i < sentence.size(); ++i)
    {
        Symbol predecessor, successor;

        if(i > 0)
        {
            predecessor = sentence[i - 1];
        }

        if(i + 1 < sentence.size())
        {
            successor = sentence[i + 1];
        }

        std::vector<Symbol> newSymbols = this->parseSymbol(predecessor, sentence[i], successor);
        for (auto symbol : newSymbols)
        {
            newSentence.push_back(symbol);
        }
    }

    return newSentence;
}

std::string Lindenmayer::toString(const std::vector<Symbol>& symbols)
{
    std::string sentence = "";

    for(size_t i = 0; i < symbols.size(); ++i)
    {
        sentence += symbols[i].toString();
    }

    return sentence;
}
