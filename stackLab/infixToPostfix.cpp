#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check the precedence of an operator
int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return -1;
}

// Function to convert infix expression to postfix
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    for (char c : infix) {
        if (isalnum(c)) {
            // If the character is an operand, append it to the postfix expression
            postfix += c;
        } else if (c == '(') {
            // If the character is an opening parenthesis, push it onto the stack
            s.push(c);
        } else if (c == ')') {
            // If the character is a closing parenthesis, pop operators from the stack
            // and append them to the postfix expression until an opening parenthesis is encountered
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            // Pop the opening parenthesis from the stack
            if (!s.empty() && s.top() == '(')
                s.pop();
        } else {
            // If the character is an operator
            while (!s.empty() && precedence(c) <= precedence(s.top())) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    // Pop any remaining operators from the stack and append them to the postfix expression
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}