#include <iostream>
using namespace std;

// Node class to represent a single node in the linked list
class Node {
public:
    int data;
    int priority;
    Node* next;

    Node(int value, int p) {
        data = value;
        priority = p;
        next = nullptr;
    }
};

// Priority Queue class to implement the priority queue using a linked list
class PriorityQueue {
private:
    Node* front;

public:
    PriorityQueue() {
        front = nullptr;
    }

    bool isEmpty() {
        return (front == nullptr);
    }

    void enqueue(int item, int p) {
        Node* newNode = new Node(item, p);
        if (isEmpty() || p < front->priority) {
            newNode->next = front;
            front = newNode;
        } else {
            Node* temp = front;
            while (temp->next != nullptr && p >= temp->next->priority) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Priority Queue is empty" << endl;
            return -1;
        }
        int item = front->data;
        Node* temp = front;
        front = front->next;
        delete temp;
        return item;
    }

    void display() {
        if (isEmpty()) {
            cout << "Priority Queue is empty" << endl;
            return;
        }
        cout << "Priority Queue: ";
        Node* temp = front;
        while (temp != nullptr) {
            cout << "(" << temp->data << "," << temp->priority << ") ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    pq.enqueue(10, 2);
    pq.enqueue(20, 1);
    pq.enqueue(15, 3);
    pq.enqueue(5, 4);
    pq.display();  // Output: Priority Queue: (20,1) (10,2) (15,3) (5,4)
    cout << pq.dequeue() << endl;  // Output: 20
    pq.display();  // Output: Priority Queue: (10,2) (15,3) (5,4)
    return 0;
}