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

// Delete a given node (pointer)
void deleteNode(Node*& head, Node* delNode) {
	if (head == nullptr || delNode == nullptr) return;

	if (head == delNode) {
		head = delNode->next; // move head
	}
	if (delNode->next != nullptr) {
		delNode->next->prev = delNode->prev;
	}
	if (delNode->prev != nullptr) {
		delNode->prev->next = delNode->next;
	}
	delete delNode;
}

// Delete by value (find first node with value)
void deleteByValue(Node*& head, int key) {
	Node* temp = head;
	while (temp != nullptr) {
		if (temp->data == key) {
			deleteNode(head, temp);
			cout << "Node with value " << key << " deleted.\n";
			return;
		}
		temp = temp->next;
	}
	cout << "Value " << key << " not found in list.\n";
}

// Display List
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
		cout << "2. Delete by value\n";
		cout << "3. Display list\n";
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
				cout << "Enter value to delete: ";
				cin >> val;
				deleteByValue(head, val);
				break;

			case 3:
				cout << "Doubly Linked List: ";
				display(head);
				break;

			case 4:
				return 0;

			default:
				cout << "Invalid choice!\n";
		}
	}
}
