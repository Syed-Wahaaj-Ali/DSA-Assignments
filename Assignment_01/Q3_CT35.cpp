/*
Assignment 01

Question 3:
Write a program to find the middle node of a singly linked list.

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
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// function to insert at end
void insert(Node*& head, int val) {
    Node* n = new Node(val);
    if (head == nullptr) {
        head = n;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = n;
}

// function to print linked list
void print(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr\n";
}

// function to find middle node(s) using slow-fast pointer method
void findMiddle(Node* head) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }

    Node* slow = head;
    Node* fast = head;
    Node* prevSlow = nullptr;

    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        prevSlow = slow;
        slow = slow->next;
    }

    if (fast == nullptr) {
        // even case will have 2 middle values
        cout << "Middle nodes are: " << prevSlow->data << " and " << slow->data << endl;
    } else {
        // odd case will give 1 middle value
        cout << "Middle node is: " << slow->data << endl;
    }
}

int main() {
    Node* head = nullptr;
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insert(head, val);
    }

    cout << "Linked List: ";
    print(head);

    findMiddle(head);

    return 0;
}
