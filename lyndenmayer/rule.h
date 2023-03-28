#ifndef RULE_H
#define RULE_H

#include "symbol.h"

// Левая часть правила вывода
class RuleHead
{
#define CONDITION_SYMBOL ':'
#define CONTEXT_LEFT_SYMBOL '<'
#define CONTEXT_RIGHT_SYMBOL '>'

public:
    RuleHead() = default;
    RuleHead(const std::string& rule);

    std::string getCondition() const;
    Symbol getPredecessor() const;
    Symbol getSuccessor() const;
    Symbol getSymbol() const;

private:
    Symbol predecessor;
    Symbol symbol;
    Symbol successor;
    std::string condition;
};

// Правая часть правила вывода
class RuleBody
{
public:
    RuleBody() = default;
    RuleBody(const std::string& rule);

    std::vector<Symbol> getBody();

private:
    std::vector<Symbol> body;
};

// Правило вывода
class Rule
{
#define EQUALS_SYMBOL '='

public:
    Rule(const std::string& rule);
    std::vector<Symbol> apply(const Symbol& symbol,
                              const Symbol& predecessor,
                              const Symbol& successor);
    bool isApplicable(const Symbol& symbol,
                      const Symbol& predecessor,
                      const Symbol& successor);
    std::vector<std::string> getKeys(const Symbol& symbol,
                                     const Symbol& predecessor,
                                     const Symbol& successor);
    RuleBody getBody() const;
    RuleHead getHead() const;

    void setKey(const Symbol& symbol,
                const Symbol& predecessor,
                const Symbol& successor);

private:
    RuleHead head;
    RuleBody body;
    std::vector<std::string> keys;
};

#endif // RULE_H
