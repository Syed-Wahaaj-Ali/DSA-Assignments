/*
Assignment #2
Question 1:
Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid. An input string is valid if open brackets
are closed by the same type of brackets in the correct order.
*/

#include <iostream>
#include <stack>
using namespace std;

/*
   Name: Syed Wahaaj Ali
   Roll No: CT-24035
   Section A - CSIT
*/

bool isValidBracket(const string& s) {
    stack<char> st;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if (st.empty()) return false;
            if ((c == ')' && st.top() != '(') ||
                (c == '}' && st.top() != '{') ||
                (c == ']' && st.top() != '[')) {
                return false;
            }
            st.pop();
        }
    }

    return st.empty();
}

int main() {
    string input;
    cout << "Enter a string of brackets: ";
    getline(cin, input);

    if (isValidBracket(input))
        cout << "Brackets are valid.\n";
    else
        cout << "Brackets are not valid.\n";

    return 0;
}
