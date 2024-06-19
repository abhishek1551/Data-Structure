#include "Calculator.h"
#include "LinkedStack.h"
#include <iostream>
#include <stack>


bool InfixCalculator::isWellFormed(std::string expression) {
    // Check if the expression is well-formed
    std::stack<char> s;
    for (std::string::iterator it = expression.begin(); it != expression.end(); ++it) {
        char c = *it;
        if (c == '(' || c == '[' || c == '{') {
            s.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (s.empty()) {
                return false;
            } else if (c == ')' && s.top() == '(') {
                s.pop();
            } else if (c == ']' && s.top() == '[') {
                s.pop();
            } else if (c == '}' && s.top() == '{') {
                s.pop();
            } else {
                return false;
            }
        }
    }
    return s.empty();
}

bool InfixCalculator::isBalanced(std::string expression) {
    // Check if the brackets are balanced
    int count = 0;
    for (int i = 0; i < expression.length(); i++) {
        char c = expression[i];
        if (c == '(' || c == '[' || c == '{') {
            count++;
        } else if (c == ')' || c == ']' || c == '}') {
            count--;
        }
        if (count < 0) {
            return false;
        }
    }
    return count == 0;
}


std::string InfixCalculator::infixToPostfix(std::string expression) {
    // Convert infix expression to postfix
    std::string postfixExpression = "";
    LinkedStack<char> stack;
    for (std::string::iterator it = expression.begin(); it != expression.end(); it++) {
        char c = *it;
        if (isdigit(c)) {
            postfixExpression += c;
        } else if (c == '(') {
            stack.push(c);
        } else if (c == ')') {
            while (!stack.isEmpty() && stack.peek() != '(') {
                postfixExpression += stack.pop();
            }
            if (!stack.isEmpty() && stack.peek() == '(') {
                stack.pop();
            }
        } else {
            while (!stack.isEmpty() && getPrecedence(c) <= getPrecedence(stack.peek())) {
                postfixExpression += stack.pop();
            }
            stack.push(c);
        }
    }
    while (!stack.isEmpty()) {
        postfixExpression += stack.pop();
    }
    return postfixExpression;
}

int InfixCalculator::getPrecedence(char op) {
    // Determine the precedence of an operator
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else {
        return 0;
    }
}
int InfixCalculator::evaluatePostfix(std::string expression) {
    LinkedStack<int> stack;
    for (int i = 0; i < expression.length(); i++) {
        char currentChar = expression[i];
        if (isdigit(currentChar)) {
            stack.push(currentChar - '0');
        } else if (currentChar == '+' || currentChar == '-' ||
                   currentChar == '*' || currentChar == '/') {
            int operand2 = stack.pop();
            int operand1 = stack.pop();
            int result;
            switch (currentChar) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*': 
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 == 0) {
                        std::cerr << "Error: Division by zero\n";
                        exit(1);
                    }
                    result = operand1 / operand2;
                    break;
            }
            stack.push(result);
        }
    }
    return stack.pop();
}
InfixCalculator::InfixCalculator() {
    infixExpression = "";
}
bool InfixCalculator::setExpression(std::string expression) {
    if (!isWellFormed(expression) || !isBalanced(expression)) {
        return false;
    }
    infixExpression = expression;
    return true;
}

int InfixCalculator::evaluate() {
    std::string postfixExpression = infixToPostfix(infixExpression);
    int result = evaluatePostfix(postfixExpression);
    return result;
}




