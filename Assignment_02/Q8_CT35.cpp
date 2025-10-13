/*
Question 8:
Implement a queue using a list or an array. Include the basic operations: enqueue (add an
element), dequeue (remove an element), peek (view the front element), and is_empty.
*/

#include <iostream>
using namespace std;

/*
   Name: Syed Wahaaj Ali
   Roll No: CT-24035
   Section A - CSIT
*/

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    ~Queue() {
        while (!isEmpty()) dequeue();
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int val) {
        Node* n = new Node(val);
        if (isEmpty()) {
            front = rear = n;
        } else {
            rear->next = n;
            rear = n;
        }
        cout << val << " enqueued successfully.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }

        cout << front->data << " dequeued.\n";
        Node* temp = front;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        delete temp;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return -1;
        }
        return front->data;
    }

    void print() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "\nQueue contents: ";
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n========== QUEUE MENU ==========";
        cout << "\n1. Enqueue (Add Element)";
        cout << "\n2. Dequeue (Remove Element)";
        cout << "\n3. Peek (Front Element)";
        cout << "\n4. Display Queue";
        cout << "\n5. Check if Empty";
        cout << "\n0. Exit";
        cout << "\n================================";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            value = q.peek();
            if (value != -1)
                cout << "Front element: " << value << endl;
            break;

        case 4:
            q.print();
            break;

        case 5:
            if (q.isEmpty()) {
                cout << "Queue is empty." << endl;
            } else {
                cout << "Queue is not empty." << endl;
            }
            break;

        case 0:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
