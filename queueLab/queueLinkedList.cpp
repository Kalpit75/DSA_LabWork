#include <iostream>
using namespace std;

// Node class to represent a single node in the linked list
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Queue class to implement the queue using a linked list
class Queue {
private:
    Node* front;
    Node* rear;
    int size;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    bool isEmpty() {
        return (size == 0);
    }

    void enqueue(int item) {
        Node* newNode = new Node(item);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int item = front->data;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        size--;
        return item;
    }

    int getSize() {
        return size;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Front -> ";
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "<- Rear" << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.display();  // Output: Front -> 1 2 3 <- Rear
    cout << q.dequeue() << endl;  // Output: 1
    q.display();  // Output: Front -> 2 3 <- Rear
    q.enqueue(4);
    q.enqueue(5);
    q.display();  // Output: Front -> 2 3 4 5 <- Rear
    return 0;
}