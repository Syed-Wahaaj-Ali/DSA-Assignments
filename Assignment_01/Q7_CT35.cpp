/*
Assignment 01

Question 7:
Write a function to insert a new node at a specific position (e.g., at the beginning, at the
end, or after a given node) in a circular singly linked list.

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

// Function to insert at beginning
void insertAtBeginning(Node*& head, int val) {
	Node* n = new Node(val);
	if (head == nullptr) {
		n->next = n; // points to itself
		head = n;
		return;
	}
	Node* temp = head;
	while (temp->next != head) {
		temp = temp->next;
	}
	temp->next = n;
	n->next = head;
	head = n; // update head
}

// Function to insert at end
void insertAtEnd(Node*& head, int val) {
	Node* n = new Node(val);
	if (head == nullptr) {
		n->next = n;
		head = n;
		return;
	}
	Node* temp = head;
	while (temp->next != head) {
		temp = temp->next;
	}
	temp->next = n;
	n->next = head;
}

// Function to insert after a given node (by value)
void insertAfter(Node* head, int key, int val) {
	if (head == nullptr) {
		cout << "List is empty\n";
		return;
	}
	Node* temp = head;
	do {
		if (temp->data == key) {
			Node* n = new Node(val);
			n->next = temp->next;
			temp->next = n;
			return;
		}
		temp = temp->next;
	} while (temp != head);

	cout << "Node with value " << key << " not found!\n";
}

// Function to display circular linked list
void display(Node* head) {
	if (head == nullptr) {
		cout << "List is empty\n";
		return;
	}
	Node* temp = head;
	do {
		cout << temp->data << " -> ";
		temp = temp->next;
	} while (temp != head);
	cout << "(back to head)\n";
}

int main() {
	Node* head = nullptr;
	int choice, val, key;

	while (true) {
		cout << "\nMenu:\n";
		cout << "1. Insert at beginning\n";
		cout << "2. Insert at end\n";
		cout << "3. Insert after a node\n";
		cout << "4. Display list\n";
		cout << "5. Exit\n";
		cout << "Enter choice: ";
		cin >> choice;

		switch (choice) {
			case 1:
				cout << "Enter value: ";
				cin >> val;
				insertAtBeginning(head, val);
				break;

			case 2:
				cout << "Enter value: ";
				cin >> val;
				insertAtEnd(head, val);
				break;

			case 3:
				cout << "Enter node value after which to insert: ";
				cin >> key;
				cout << "Enter value to insert: ";
				cin >> val;
				insertAfter(head, key, val);
				break;

			case 4:
				cout << "Circular Linked List: ";
				display(head);
				break;

			case 5:
				return 0;

			default:
				cout << "Invalid choice!\n";
		}
	}

	return 0;
}
