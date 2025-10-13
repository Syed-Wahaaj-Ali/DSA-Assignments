/*
Assignment #2
Question 9:
Implement a queue's enqueue and dequeue operations using only two stacks.
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

class Stack {
private:
    Node* topPtr;

public:
    Stack() {
        topPtr = nullptr;
    }

    void push(int val) {
        Node* n = new Node(val);
        n->next = topPtr;
        topPtr = n;
    }

    int pop() {
        if (empty()) return -1;
        int value = topPtr->data;
        Node* temp = topPtr;
        topPtr = topPtr->next;
        delete temp;
        return value;
    }

    bool empty() {
        return topPtr == nullptr;
    }

    int top() {
        if (empty()) return -1;
        return topPtr->data;
    }

    void print() {
        Node* current = topPtr;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
    }
};

class Queue {
private:
    Stack s1, s2;

public:
    void enqueue(int val) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(val);

        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    void dequeue() {
        if (s1.empty()) {
            cout << "\nQueue is empty.";
            return;
        }
        s1.pop();
    }

    bool isEmpty() {
        return s1.empty();
    }

    void print() {
        if (isEmpty()) {
            cout << "\nQueue is empty.";
            return;
        }
        s1.print();
    }
};

int main() {
    Queue q;

    for (int i = 1; i <= 10; i++) q.enqueue(i);

    cout << "Original queue: ";
    q.print();

    q.dequeue();
    cout << "\n\nAfter dequeuing 1: ";
    q.print();

    q.dequeue();
    cout << "\n\nAfter dequeuing 2: ";
    q.print();

    q.dequeue();
    cout << "\n\nAfter dequeuing 3: ";
    q.print();

    return 0;
}
