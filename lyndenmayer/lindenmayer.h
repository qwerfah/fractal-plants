#ifndef LINDENMAYER_H
#define LINDENMAYER_H

#include "rule.h"

// Lindenmayer System (parametric context-sensitive grammar)
class Lindenmayer
{
public:
    Lindenmayer();

    void setConstants(const std::string& _constants);
    void setRules(const std::vector<Rule>& _rules);
    void removeRules();
    void addRule(const std::string& rule);
    std::string process(const std::string& _axiom, size_t iterations);
    static std::vector<Symbol> toSymbols(const std::string& str);
    std::string toString(const std::vector<Symbol>& symbols);

private:
    std::vector<Rule> getApplicableRules(const Symbol& symbol,
                                         const Symbol& predecessor,
                                         const Symbol& successor);
    std::vector<Symbol> applyRule(const Rule& rule, const Symbol& symbol,
                                  const Symbol& predecessor,
                                  const Symbol& successor);
    std::vector<Symbol> parseSymbol(const Symbol& predecessor,
                                    const Symbol& symbol,
                                    const Symbol& successor);
    std::vector<Symbol> applyRules(const std::vector<Symbol>& sentence);

    std::vector<Rule> rules;
    std::string constants;
};

#endif // LINDENMAYER_H
