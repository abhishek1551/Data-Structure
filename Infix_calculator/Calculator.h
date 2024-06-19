#ifndef INFIXCALCULATOR_H
#define INFIXCALCULATOR_H

#include <string>

class InfixCalculator {
private:
    std::string infixExpression;

    bool isWellFormed(std::string expression);
    bool isBalanced(std::string expression);
    std::string infixToPostfix(std::string expression);
    int getPrecedence(char op);
    int evaluatePostfix(std::string expression);

public:
    InfixCalculator();
    bool setExpression(std::string expression);
    int evaluate();
};
#endif

