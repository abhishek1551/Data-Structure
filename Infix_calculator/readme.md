# Infix Expression Calculator

## Overview
This project implements an infix expression calculator using a custom linked stack data structure.
The calculator supports conversion of infix expressions to postfix (Reverse Polish Notation, RPN) expressions
and evaluation of these postfix expressions.

## Features
- **Infix to Postfix Conversion**: Converts infix mathematical expressions to postfix notation.
- **Expression Evaluation**: Evaluates postfix expressions using a stack.
- **Expression Validation**: Checks if the infix expression is well-formed and balanced.

## Components
- **InfixCalculator Class**: Handles expression validation, conversion, and evaluation.
- **LinkedStack Class**: Implements a stack using a linked list.
- **Main Function**: Provides a user interface for inputting and evaluating expressions.

## Files
- `Calculator.h` and `Calculator.cpp`: Contains the `InfixCalculator` class.
- `LinkedStack.h` and `LinkedStack.cpp`: Contains the `LinkedStack` class.
- `StackInterface.h`: Defines the stack interface.
- `PrecondViolatedException.h`: Defines an exception class for precondition violations.
- `main.cpp`: Contains the main function to run the calculator.


