/*
Assignment #2
Question 4:
Implement an algorithm that converts an arithmetic expression from infix notation to postfix notation using a stack.
For example, (A + B) * C becomes AB+C*.
*/

#include <iostream>
#include <stack>
using namespace std;

/*
   Name: Syed Wahaaj Ali
   Roll No: CT-24035
   Section A - CSIT
*/

int findPrecedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isRightAssociative(char op) {
    return op == '^';
}

string infixToPostfix(string s) {
    string postfix;
    stack<char> st;

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];

        if (c == ' ') continue;

        if ((c >= 'A' && c <= 'Z') || 
            (c >= 'a' && c <= 'z') || 
            (c >= '0' && c <= '9')) {
            postfix += c;
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop(); // remove '('
        }
        else { // operator
            while (!st.empty() &&
                  ((findPrecedence(st.top()) > findPrecedence(c)) || (findPrecedence(st.top()) == findPrecedence(c) && !isRightAssociative(c))) && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main() {
    string s;
    cout << "Enter a string to convert to postfix: ";
    getline(cin, s);

    cout << "Infix to Postfix: " << infixToPostfix(s) << endl;
    return 0;
}
