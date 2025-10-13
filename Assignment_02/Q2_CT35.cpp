/*
Assignment #2
Question 2:
Use a stack to reverse a given string.
*/

#include <iostream>
#include <stack>
using namespace std;

/*
   Name: Syed Wahaaj Ali
   Roll No: CT-24035
   Section A - CSIT
*/

string reverseString(string str) {
    stack<char> st;

    for (int i = 0; i < str.length(); i++) {
        st.push(str[i]);
    }

    string reversed = "";
    while (!st.empty()) {
        reversed += st.top();
        st.pop();
    }

    return reversed;
}

int main() {
    string str;

    cout << "Enter a string: ";
    getline(cin, str);

    str reversed = reverseString(str);

    cout << "Reversed string: " << reversed << endl;
    return 0;
}
