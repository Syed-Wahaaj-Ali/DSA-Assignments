/*
Assignment #2
Question 6:
Design a stack that, in addition to the standard push and pop operations, also has a get_min operation that returns the minimum element. 
All three operations should have a time complexity of O(1).
*/

#include <iostream>
#include <climits>
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
    Node(int val) : data(val), next(nullptr) {}
};

class Stack {
private:
    Node* top;  
    Node* minTop; 

public:
    Stack() {
        top = nullptr;
        minTop = nullptr;
    }

    bool empty() {
        return top == nullptr;
    }

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;

        if (minTop == nullptr || val <= minTop->data) {
            Node* newMin = new Node(val);
            newMin->next = minTop;
            minTop = newMin;
        }
    }

    int pop() {
        if (empty()) {
            cout << "\nStack is empty! Cannot pop.\n";
            return -1;
        }

        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;

        if (value == minTop->data) {
            Node* minTemp = minTop;
            minTop = minTop->next;
            delete minTemp;
        }

        return value;
    }

    int get_min() {
        if (minTop == nullptr) {
            cout << "\nStack is empty!\n";
            return INT_MAX;
        }
        return minTop->data;
    }

    void display() {
        if (empty()) {
            cout << "\nStack is empty.\n";
            return;
        }

        cout << "\nCurrent stack elements (top to bottom): ";
        Node* current = top;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Stack st;
    int n, value, choice;

    cout << "Enter the number of elements to push: ";
    cin >> n;

    cout << "\nEnter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        st.push(value);
    }

    st.display();
    cout << "Current Minimum: " << st.get_min() << endl;

    cout << "\nDo you want to pop an element? (1 = Yes / 0 = No): ";
    cin >> choice;

    if (choice == 1) {
        st.pop();
        st.display();
        cout << "Current Minimum: " << st.get_min() << endl;
    }

    cout << "\nPushing a new element to check min update:\nEnter value: ";
    cin >> value;
    st.push(value);
    st.display();
    cout << "Current Minimum: " << st.get_min() << endl;

    cout << "\nProgram finished.\n";
    return 0;
}
