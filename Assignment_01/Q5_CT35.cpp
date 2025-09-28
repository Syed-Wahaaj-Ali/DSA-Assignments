/*
Assignment 01

Question 5:
Given the heads of two sorted singly linked lists, merge the two lists into a single sorted list.
The new list should be made by splicing together the nodes of the first two lists.

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

// insert node at end
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

// print linked list
void print(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr\n";
}

// recursive merge function
Node* mergeSortedRecursive(Node* l1, Node* l2) {
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;

    if (l1->data <= l2->data) {
        l1->next = mergeSortedRecursive(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeSortedRecursive(l1, l2->next);
        return l2;
    }
}

int main() {
    Node* l1 = nullptr;
    Node* l2 = nullptr;
    int n1, n2, val;

    cout << "Enter size of first sorted list: ";
    cin >> n1;
    cout << "Enter " << n1 << " sorted values:\n";
    for (int i = 0; i < n1; i++) {
        cin >> val;
        insert(l1, val);
    }

    cout << "Enter size of second sorted list: ";
    cin >> n2;
    cout << "Enter " << n2 << " sorted values:\n";
    for (int i = 0; i < n2; i++) {
        cin >> val;
        insert(l2, val);
    }

    cout << "\nFirst List: ";
    print(l1);
    cout << "Second List: ";
    print(l2);

    Node* merged = mergeSortedRecursive(l1, l2);
    cout << "\nMerged Sorted List: ";
    print(merged);
    return 0;
}
