/*
Assignment #2
Question 5:
Write a function that evaluates the postfix expression P = 5 6 2 + * 12 4 / -
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
   Name: Syed Wahaaj Ali
   Roll No: CT-24035
   Section A - CSIT
*/

int evaluatePostfix(string exp) {
    stack<int> st;
    int i = 0;

    while (i < exp.size()) {
        if (exp[i] == ' ') {
            i++;
            continue;
        }

        string token = "";
        while (i < exp.size() && exp[i] != ' ') {
            token += exp[i];
            i++;
        }

        if (isdigit(token[0])) {
            st.push(stoi(token));
        }
        else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();

            switch (token[0]) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/': st.push(a / b); break;
            }
        }
    }

    return st.top();
}

int main() {
    string postfix;
    cout << "Enter postfix expression: ";
    getline(cin, postfix);
    int result = evaluatePostfix(postfix);
    cout << "Result of postfix expression: " << result << endl;
    return 0;
}
