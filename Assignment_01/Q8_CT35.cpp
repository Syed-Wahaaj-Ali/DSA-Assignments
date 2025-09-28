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

// Node class for doubly linked list
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

// Function to delete a given node (using pointer)
void deleteNode(Node*& head, Node* del) {
    // Case 1: nothing to delete
    if (head == nullptr || del == nullptr)
        return;

    // Case 2: if node to be deleted is head
    if (head == del)
        head = del->next;

    // Case 3: if node to be deleted is not the last node
    if (del->next != nullptr)
        del->next->prev = del->prev;

    // Case 4: if node to be deleted is not the first node
    if (del->prev != nullptr)
        del->prev->next = del->next;

    // finally free memory
    delete del;
}

// Doubly linked list class
class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() {
        head = nullptr;
    }

    // Insert node at end
    void insert(int val) {
        Node* n = new Node(val);
        if (head == nullptr) {
            head = n;
        } else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = n;
            n->prev = temp;
        }
    }

    // Display all nodes
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Get node at given position (1-based index)
    Node* getNodeAt(int pos) {
        Node* temp = head;
        int count = 1;
        while (temp != nullptr && count < pos) {
            temp = temp->next;
            count++;
        }
        return temp; // will be nullptr if pos > length
    }
};

int main() {
    DoublyLinkedList list;
    int n, val;

    cout << "Enter number of elements to insert: ";
    cin >> n;

    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        list.insert(val);
    }

    cout << "List: ";
    list.display();

    int pos;
    cout << "Enter position of node to delete: ";
    cin >> pos;

    Node* del = list.getNodeAt(pos);
    if (del != nullptr) {
        deleteNode(list.head, del);
        cout << "List after deletion: ";
        list.display();
    } else {
        cout << "Invalid position, no deletion performed.\n";
    }

    return 0;
}
