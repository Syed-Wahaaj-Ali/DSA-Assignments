/*
Assignment 01

Question 10: Given a circular singly linked list, rotate it by k positions.
For example, with n=7 and k=3, the list 1, 2, 3, 4, 5, 6, 7
becomes 5, 6, 7, 1, 2, 3, 4.

*/

#include <iostream>
using namespace std;

/*
   Name: Syed Wahaaj Ali
   Roll No: CT-24035
   Section A - CSIT
*/

// Node class for circular linked list
class Node {
	public:
		int data;
		Node* next;

		Node(int data) {
			this->data = data;
			next = nullptr;
		}
};

// Circular linked list class
class CircularList {
	public:
		Node* head;
		Node* tail;
		int size;

		// constructor
		CircularList() {
			head = tail = nullptr;
			size = 0;
		}

		// check if list is empty
		bool isEmpty() {
			return head == nullptr;
		}

		// insert value at the end
		void push_back(int val) {
			Node* newNode = new Node(val);
			size++;

			// if first node
			if (isEmpty()) {
				head = tail = newNode;
				tail->next = head; // circular link
				return;
			}

			// otherwise add at end
			tail->next = newNode;
			tail = newNode;
			tail->next = head; // maintain circular link
		}

		// rotate list by k positions
		void rotate(int k) {
			if (isEmpty() || head->next == head || k == 0) return;

			// handle cases where k > size
			k = k % size;
			if (k == 0) return;

			// move to (size-k)th node (new tail)
			Node* curr = head;
			for (int i = 1; i < size - k; i++) {
				curr = curr->next;
			}

			// update head and tail
			head = curr->next;
			tail = curr;
		}

		// display list
		void print() {
			if (isEmpty()) {
				cout << "List is empty\n";
				return;
			}

			Node* temp = head;
			do {
				cout << temp->data << " -> ";
				temp = temp->next;
			} while (temp != head);

			cout << "(back to head)" << endl;
		}
};

int main() {
	CircularList c;
	int n, k, val;

	// input number of nodes
	cout << "Enter the number of elements for linked list: ";
	cin >> n;

	// input values
	cout << "Enter " << n << " values: ";
	for (int i = 0; i < n; i++) {
		cin >> val;
		c.push_back(val);
	}

	// input k
	cout << "Enter the kth position to rotate list: ";
	cin >> k;

	// original list
	cout << "\nOriginal list: ";
	c.print();

	// perform rotation
	c.rotate(k);

	// rotated list
	cout << "Rotated list: ";
	c.print();
	return 0;
}
