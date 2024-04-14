#include <iostream>
using namespace std;

class Queue {
private:
    int *arr;
    int capacity;
    int front, rear, size;

public:
    Queue(int c) {
        capacity = c;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    bool isEmpty() {
        return (size == 0);
    }

    bool isFull() {
        return (size == capacity);
    }

    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = item;
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int item = arr[front];
        front = (front + 1) % capacity;
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
        cout << "Front: " << front << endl;
        cout << "Rear: " << rear << endl;
        cout << "Items in the queue: ";
        for (int i = front; i != (rear + 1) % capacity; i = (i + 1) % capacity) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.display();  // Output: Front: 0, Rear: 2, Items in the queue: 1 2 3
    cout << q.dequeue() << endl;  // Output: 1
    q.display();  // Output: Front: 1, Rear: 2, Items in the queue: 2 3
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);  // Output: Queue is full
    q.display();  // Output: Front: 1, Rear: 0, Items in the queue: 2 3 4 5
    return 0;
}