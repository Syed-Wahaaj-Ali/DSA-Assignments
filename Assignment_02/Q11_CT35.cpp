/*
Assignment #2
Question 11:
You are given a queue with N elements. You can perform two operations: Left-Shift (dequeue from the
front) and Right-Shift (dequeue from the rear). Implement an algorithm to find the minimum number
of operations to make the queue empty.
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
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
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

    void enqueue(int val) {
        Node* n = new Node(val);
        if (front == nullptr) {
            front = rear = n;
            return;
        }
        rear->next = n;
        n->prev = rear;
        rear = n;
    }

    void dequeueFront() {
        if (front == nullptr) return;
        Node* temp = front;
        front = front->next;
        if (front != nullptr) front->prev = nullptr;
        else rear = nullptr;
        delete temp;
    }

    void dequeueEnd() {
        if (rear == nullptr) return;
        Node* temp = rear;
        rear = rear->prev;
        if (rear != nullptr) rear->next = nullptr;
        else front = nullptr;
        delete temp;
    }

    bool empty() {
        return front == nullptr;
    }

    int minOperationsToEmpty() {
        int count = 0;
        while (!empty()) {
            dequeueFront();  
            count++;
            if (!empty()) {
                dequeueEnd();
                count++;
            }
        }
        return count;
    }

    void print() {
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
    int N;
    cout << "Enter number of elements: ";
    cin >> N;

    cout << "Enter elements:\n";
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        q.enqueue(x);
    }

    cout << "\nOriginal queue: ";
    q.print();

    int ops = q.minOperationsToEmpty();
    cout << "\nMinimum operations to empty the queue: " << ops << endl;

    return 0;
}
