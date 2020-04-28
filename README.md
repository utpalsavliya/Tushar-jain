# Infix to Postfix
This program takes an infix expression as an input and outputs a corresponding postfix expression.

### Supported operations in input (according to precedence) :

- __'(' ')'__ - Braces.
- __'^'__ - Exponentiation.
- __'/' '*'__ - Multiplication and division.
- __'+' '-'__ - Addition and Substraction.

The input can have numbers, letters and any other symbols as operands as long as they are not identified as supported operands.

More supported operands can be added as a case in the `GetOperatorWeight()` function, modifying the `weight` variable corresponding to their precedence. Greater the precendence of an operand, more is the weight of the operand.

> Note - we are checking __'S.empty()'__ condition at every stage when we are making changes in Stack as S.top() is unexpected behaviour when stack is empty.

> The program currently doesn't support space between characters, and will end the input on first occurence of any space character.

## TestCases.md

This file contains test cases along with the expected outputs in a tabular form. Use these to test the program in case modifications are made.
