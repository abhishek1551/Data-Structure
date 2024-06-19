#include <iostream>
#include <string>
#include "Calculator.h"

int main() {
    std::string input;
    Calculator calculator;

    while (true) {
        std::cout << "Enter an infix expression";
        std::getline(std::cin, input);

        calculator.setExpression(input);        
        if (!calculator.isBalanced()) {
            std::cout << "Error: Expression has unbalanced parentheses." << std::endl;
            continue;
        }

        std::cout << "Infix expression: " << calculator.getExpression() << std::endl;
        std::cout << "Postfix expression: " << calculator.convertToPostfix() << std::endl;
        std::cout << "Result: " << calculator.evaluate() << std::endl;
    }

    return 0;
}

