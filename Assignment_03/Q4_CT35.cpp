/*
Assignment #3
Question 4:
Write a recursive function to reverse a given string. Do not use any loops or built-in reverse
functions.
*/

#include <iostream>
using namespace std;

/*
   Name: Syed Wahaaj Ali
   Roll No: CT-24035
   Section A - CSIT
*/

string reverseString(string str) {
    if (str.length() <= 1)
        return str;
    return str.back() + reverseString(str.substr(0, str.length()-1));
}

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);
    cout << "Reversed string: " << reverseString(s) << endl;
    return 0;
}
