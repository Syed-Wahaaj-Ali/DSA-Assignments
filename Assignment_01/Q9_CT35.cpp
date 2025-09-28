/*
Assignment 01

Question 9:
Write a function to reverse a doubly linked list. Your solution should correctly update the
next and prev pointers for each node.

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
		Node* prev;
		Node* next;
		Node(int val) {
			data = val;
			prev = nullptr;
			next = nullptr;
		}
};

// Insert at end
void insertAtEnd(Node*& head, int val) {
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
	n->prev = temp;
}

// Reverse list
void reverseList(Node*& head) {
	if (head == nullptr || head->next == nullptr) return;

	Node* current = head;
	Node* temp = nullptr;

	while (current != nullptr) {
		// Swap prev and next for current
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;

		// Move to next node (which is actually prev now)
		current = current->prev;
	}

	// Fix head (after loop, temp will be at new head's prev)
	if (temp != nullptr) {
		head = temp->prev;
	}
	cout << "List reversed successfully.\n";
}

// Display list
void display(Node* head) {
	if (head == nullptr) {
		cout << "List is empty\n";
		return;
	}
	Node* temp = head;
	while (temp != nullptr) {
		cout << temp->data << " <-> ";
		temp = temp->next;
	}
	cout << "NULL\n";
}

int main() {
	Node* head = nullptr;
	int choice, val;

	while (true) {
		cout << "\nMenu:\n";
		cout << "1. Insert at end\n";
		cout << "2. Display list\n";
		cout << "3. Reverse list\n";
		cout << "4. Exit\n";
		cout << "Enter choice: ";
		cin >> choice;

		switch (choice) {
			case 1:
				cout << "Enter value: ";
				cin >> val;
				insertAtEnd(head, val);
				break;

			case 2:
				cout << "Doubly Linked List: ";
				display(head);
				break;

			case 3:
				reverseList(head);
				break;

			case 4:
				return 0;

			default:
				cout << "Invalid choice!\n";
		}
	}
}
