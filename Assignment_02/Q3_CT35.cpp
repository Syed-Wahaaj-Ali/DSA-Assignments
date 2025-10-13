/*
Assignment #2
Question 3:
Write a program that takes a decimal number and uses a stack to convert it to its binary representation.
*/

#include <iostream>
#include <stack>
using namespace std;

/*
   Name: Syed Wahaaj Ali
   Roll No: CT-24035
   Section A - CSIT
*/

string decimalToBinary(int decimal) {
    if (decimal == 0) return "0";

    stack<int> st;
    string binary = "";

    while (decimal > 0) {
        int remainder = decimal % 2;
        st.push(remainder);
        decimal /= 2;
    }

    while (!st.empty()) {
        binary += to_string(st.top());
        st.pop();
    }

    return binary;
}

int main() {
    int decimal;

    cout << "Enter a decimal number: ";
    cin >> decimal;

    string binary = decimalToBinary(decimal);

    cout << "Binary representation: " << binary << endl;
    return 0;
}
