#include <iostream>
#include <string>
#include <stack>

using namespace std;

// Recursive function to evaluate an arithmetic expression
int evaluate(string expr) {
    stack<char> operators;
    stack<int> operands;
    int num = 0;
    bool isNum = false;
    char op;

    for (int i = 0; i < expr.length(); i++) {
        char c = expr[i];
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
            isNum = true;
        }
        else if (c == '(') {
            int j = i + 1;
            int cnt = 1;
            while (cnt != 0) {
                if (expr[j] == '(') cnt++;
                else if (expr[j] == ')') cnt--;
                j++;
            }
            num = evaluate(expr.substr(i + 1, j - i - 2));
            i = j - 1;
            isNum = true;
        }
        else if (isNum) {
            operands.push(num);
            num = 0;
            isNum = false;
        }
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!operators.empty() && 
                   ((operators.top() == '*' || operators.top() == '/') ||
                   ((operators.top() == '+' || operators.top() == '-') && (c == '+' || c == '-')))) {
                int b = operands.top();
                operands.pop();
                int a = operands.top();
                operands.pop();
                op = operators.top();
                operators.pop();
                switch (op) {
                    case '+':
                        operands.push(a + b);
                        break;
                    case '-':
                        operands.push(a - b);
                        break;
                    case '*':
                        operands.push(a * b);
                        break;
                    case '/':
                        operands.push(a / b);
                        break;
                }
            }
            operators.push(c);
        }
    }

    if (isNum) {
        operands.push(num);
    }

    while (!operators.empty()) {
        int b = operands.top();
        operands.pop();
        int a = operands.top();
        operands.pop();
        op = operators.top();
        operators.pop();
        switch (op) {
            case '+':
                operands.push(a + b);
                break;
            case '-':
                operands.push(a - b);
                break;
            case '*':
                operands.push(a * b);
                break;
            case '/':
                operands.push(a / b);
                break;
        }
    }

    return operands.top();
}

int main() {
    string expr;
    while(getline(cin, expr)){
        cout << evaluate(expr) << endl;
    }

    return 0;
}
