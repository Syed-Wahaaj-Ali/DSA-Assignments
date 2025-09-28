/*
Assignment 01

Question 6:
Given the head of a linked list, remove the n nodes from the list and return its head.

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

void insertAtEnd(Node*& head, int val) {
	Node* newNode = new Node(val);
	if (head == nullptr) {
		head = newNode;
		return;
	}
	Node* temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	temp->next = newNode;
}

void display(Node* head) {
	Node* temp = head;
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

Node* removeNNodes(Node* head, int n) {
	while (head != nullptr && n > 0) {
		Node* temp = head;
		head = head->next;
		delete temp;
		n--;
	}
	return head; // new head after removing nodes
}

int main() {
	Node* head = nullptr;
	int n, val;

	cout << "Enter number of elements: ";
	cin >> n;

	cout << "Enter elements: ";
	for (int i = 0; i < n; i++) {
		cin >> val;
		insertAtEnd(head, val);
	}

	cout << "Original list: ";
	display(head);
	if (head != nullptr) cout << "Original head = " << head->data << endl;

	int a;
	cout << "Enter number of nodes to remove from head: ";
	cin >> a;

	head = removeNNodes(head, a);

	cout << "Updated list: ";
	display(head);
	if (head != nullptr)
		cout << "New head = " << head->data << endl;
	else
		cout << "List is empty, head = nullptr" << endl;
	return 0;
}
