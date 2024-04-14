#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

// Function to evaluate a postfix expression
int evaluatePostfix(string expression) {
    stack<int> s; // Stack to store operands

    for (char c : expression) {
        if (isdigit(c)) {
            // If the character is a digit, push it onto the stack
            s.push(c - '0');
        } else {
            // If the character is an operator
            int op2 = s.top();
            s.pop();
            int op1 = s.top();
            s.pop();

            // Perform the operation
            switch (c) {
                case '+':
                    s.push(op1 + op2);
                    break;
                case '-':
                    s.push(op1 - op2);
                    break;
                case '*':
                    s.push(op1 * op2);
                    break;
                case '/':
                    s.push(op1 / op2);
                    break;
            }
        }
    }

    // The remaining element in the stack is the result
    return s.top();
}

int main() {
    string expression;
    cout << "Enter a postfix expression: ";
    getline(cin, expression);

    int result = evaluatePostfix(expression);
    cout << "Result: " << result << endl;

    return 0;
}
