/*
Assignment 01

Question 8:
Implement a function to delete a node from a doubly linked list, given a pointer to the
node to be deleted.

*/

#include <iostream>
using namespace std;

/*
   Name: Syed Wahaaj Ali
   Roll No: CT-24035
   Section A - CSIT
*/

// Node structure for circular linked list
class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = nullptr; // initially null
    }
};

// Function to create circular linked list
Node* createCircularList(int n) {
    if (n <= 0) return nullptr;

    int val;
    cout << "Enter " << n << " values: ";
    cin >> val;
    Node* head = new Node(val);
    Node* temp = head;

    for (int i = 1; i < n; i++) {
        cin >> val;
        temp->next = new Node(val);
        temp = temp->next;
    }
    temp->next = head; // last node points to head
    return head;
}

// Function to display circular list
void display(Node* head, int n) {
    if (!head) return;
    Node* temp = head;
    for (int i = 0; i < n; i++) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "(back to head)" << endl;
}

// Function to rotate circular list by k positions
Node* rotate(Node* head, int k, int n) {
    if (!head || k % n == 0) return head; // no change if k is multiple of n

    int steps = n - (k % n); // find new head position
    Node* temp = head;

    // move to (steps-1)th node
    for (int i = 1; i < steps; i++) {
        temp = temp->next;
    }

    // new head will be next of temp
    head = temp->next;
    return head;
}

int main() {
    int n, k;
    cout << "Enter number of nodes: ";
    cin >> n;

    Node* head = createCircularList(n);

    cout << "Original list: ";
    display(head, n);

    cout << "Enter the kth position to rotate list: ";
    cin >> k;

    head = rotate(head, k, n);

    cout << "Rotated list: ";
    display(head, n);

    return 0;
}
