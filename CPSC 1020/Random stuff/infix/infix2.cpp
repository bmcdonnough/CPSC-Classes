#include <iostream>
#include <string>
using namespace std;

int evaluateTerm(string expression, int& index);

// Function to perform arithmetic operation
int performOperation(char operation, int operand1, int operand2) {
    if (operation == '+') {
        return operand1 + operand2;
    } else if (operation == '-') {
        return operand1 - operand2;
    } else if (operation == '*') {
        return operand1 * operand2;
    } else if (operation == '/') {
        return operand1 / operand2;
    } else if (operation == '^') {
        int result = 1;
        for (int i = 0; i < operand2; i++) {
            result *= operand1;
        }
        return result;
    } else {
        // Throw an exception for invalid operator
        throw invalid_argument("Invalid operator: " + string(1, operation));
    }
}

// Function to evaluate the expression
int evaluateExpression(string expression) {
    int index = 0;
    return evaluateTerm(expression, index);
}

// Function to evaluate a term of the expression
int evaluateTerm(string expression, int& index) {
    int result = 0;
    char operation = '+';

    while (index < expression.length()) {
        // Read the next character in the expression
        char c = expression[index++];

        if (c == '(') {
            // Evaluate the sub-expression within the parentheses recursively
            int subExpressionResult = evaluateTerm(expression, index);
            result = performOperation(operation, result, subExpressionResult);
        } else if (isdigit(c)) {
            // Read the entire number and evaluate it
            int number = c - '0';
            while (index < expression.length() && isdigit(expression[index])) {
                number = number * 10 + (expression[index++] - '0');
            }
            result = performOperation(operation, result, number);
        } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            // Update the operation for the next evaluation
            operation = c;
        } else if (c == ')') {
            // Return the result for the sub-expression within the parentheses
            return result;
        }
    }

    // Return the final result for the entire expression
    return result;
}

// Main function to read input expressions and output their evaluations
int main() {
    string expression;

    while (getline(cin, expression)) {
        int result = evaluateExpression(expression);
        cout << result << endl;
    }

    return 0;
}
