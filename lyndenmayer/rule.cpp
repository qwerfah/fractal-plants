#include "rule.h"
#include "utilities.h"

// Разбиение левой части на символ, предшественника и потомка
// Выделение состояния условия
RuleHead::RuleHead(const std::string& rule)
{
    size_t index = 0;
    size_t conditionIndex = rule.find(CONDITION_SYMBOL);
    size_t predecessorIndex = rule.find(CONTEXT_LEFT_SYMBOL);
    size_t successorIndex = rule.find(CONTEXT_RIGHT_SYMBOL);

    if(conditionIndex != std::string::npos)
    {
        if(predecessorIndex > conditionIndex)
        {
            predecessorIndex = std::string::npos;
        }
        if(successorIndex > conditionIndex)
        {
            successorIndex = std::string::npos;
        }
    }

    if(predecessorIndex != std::string::npos)
    {
        this->predecessor = Symbol(rule, index);
        index = predecessorIndex + 1;
    }
    else
    {
        this->predecessor = Symbol();
    }

    this->symbol = Symbol(rule, index);

    if(successorIndex != std::string::npos)
    {
        this->successor = Symbol(rule, successorIndex + 1);
    }
    else
    {
        this->successor = Symbol();
    }

    if(conditionIndex != std::string::npos)
    {
        this->condition = rule.substr(conditionIndex + 1);
    }
    else
    {
        this->condition = "";
    }
}

std::string RuleHead::getCondition() const
{
    return condition;
}

Symbol RuleHead::getPredecessor() const
{
    return predecessor;
}

Symbol RuleHead::getSuccessor() const
{
    return successor;
}

Symbol RuleHead::getSymbol() const
{
    return symbol;
}


// Тело (правая часть)
RuleBody::RuleBody(const std::string& rule)
{
    this->body = Symbol::toSymbols(rule);
}

std::vector<Symbol> RuleBody::getBody()
{
    return this->body;
}


// Разбиение правила на левую и правую часть
Rule::Rule(const std::string& rule)
{
    std::string source = removeSpaces(rule);

    this->head = RuleHead(source.substr(0, source.rfind(EQUALS_SYMBOL)));
    this->body = RuleBody(source.substr(source.rfind(EQUALS_SYMBOL) + 1,
                                        source.length()));
    this->keys = this->getKeys(this->head.getSymbol(),
                               this->head.getPredecessor(),
                               this->head.getSuccessor());
}

std::vector<Symbol> Rule::apply(const Symbol& symbol,
                                const Symbol& predecessor,
                                const Symbol& successor)
{
    std::vector<Symbol> result;
    std::vector<std::string> parameterValues = this->getKeys(symbol,
                                                             predecessor,
                                                             successor);
    for (auto s : this->body.getBody())
    {
        Symbol res = Symbol(s.getSymbol());
        if (s.getParameters().size())
        {
            std::vector<std::string> newParameters;
            for (auto param : s.getParameters())
            {
                newParameters.push_back(std::to_string(generateFunction(this->keys,
                                                                        parameterValues,
                                                                        param)));
            }
            res.setParameters(newParameters);
        }
        result.push_back(res);
    }

    return result;
}

bool Rule::isApplicable(const Symbol& symbol,
                        const Symbol& predecessor,
                        const Symbol& successor)
{
    if(!symbol.matches(this->head.getSymbol()))
    {
        return false;
    }
    if(this->head.getPredecessor() && !this->head.getPredecessor().matches(predecessor))
    {
        return false;
    }
    if(this->head.getSuccessor() && !this->head.getSuccessor().matches(successor))
    {
        return false;
    }

    std::vector<std::string> values = getKeys(symbol, predecessor, successor);

    if(this->head.getCondition().length())
    {
        return generateFunction(this->keys, values, this->head.getCondition());
    }

    return true;
}

std::vector<std::string> Rule::getKeys(const Symbol& symbol,
                                       const Symbol& predecessor,
                                       const Symbol& successor)
{
    std::vector<std::string> keys;

    if (this->head.getPredecessor())
    {
        for (auto parameter : predecessor.getParameters())
        {
            keys.push_back(parameter);
        }
    }

    for (auto parameter : symbol.getParameters())
    {
        keys.push_back(parameter);
    }

    if (this->head.getSuccessor())
    {
        for (auto parameter : successor.getParameters())
        {
            keys.push_back(parameter);
        }
    }

    return keys;
}

RuleBody Rule::getBody() const
{
    return this->body;
}

RuleHead Rule::getHead() const
{
    return this->head;
}
