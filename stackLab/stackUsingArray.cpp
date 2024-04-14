#include <iostream>
using namespace std;

#define MAX_SIZE 100 // Maximum size of the stack

class Stack {
private:
    int arr[MAX_SIZE]; // Array to store stack elements
    int top; // Index of the top element

public:
    Stack() {
        top = -1; // Initialize top to -1 (empty stack)
    }

    bool isEmpty() {
        return top == -1; // Check if the stack is empty
    }

    bool isFull() {
        return top == MAX_SIZE - 1; // Check if the stack is full
    }

    void push(int x) {
        if (isFull()) {
            cout << "Error: Stack is full" << endl;
            return;
        }
        arr[++top] = x; // Increment top and insert the element
        cout << x << " pushed into the stack" << endl;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Error: Stack is empty" << endl;
            return -1; // Return a sentinel value indicating an error
        }
        int x = arr[top--]; // Get the top element and decrement top
        cout << x << " popped from the stack" << endl;
        return x;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Error: Stack is empty" << endl;
            return -1; // Return a sentinel value indicating an error
        }
        return arr[top]; // Return the top element without removing it
    }

    int size() {
        return top + 1; // Return the number of elements in the stack
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top element: " << s.peek() << endl;
    cout << "Size of the stack: " << s.size() << endl;
    s.pop();
    s.pop();
    s.pop();
    if (s.isEmpty()) {
        cout << "Stack is empty" << endl;
    }
    return 0;
}