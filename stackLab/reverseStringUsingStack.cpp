#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to reverse a string using a stack
string reverseString(string str) {
    stack<char> s;
    string reversed = "";

    // Push each character of the string onto the stack
    for (char c : str) {
        s.push(c);
    }

    // Pop characters from the stack and append them to the reversed string
    while (!s.empty()) {
        reversed += s.top();
        s.pop();
    }

    return reversed;
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    string reversedStr = reverseString(str);
    cout << "Reversed string: " << reversedStr << endl;

    return 0;
}