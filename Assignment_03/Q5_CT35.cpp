/*
Assignment #3
Question 5:
Implement a recursive function to check if a given string is a palindrome. A palindrome is a
word or phrase that reads the same forwards and backwards.
*/

#include <iostream>
using namespace std;

/*
   Name: Syed Wahaaj Ali
   Roll No: CT-24035
   Section A - CSIT
*/

bool isPalindrome(string s, int start, int end) {
    if (start >= end)
        return true;
    if (s[start] != s[end])
        return false;
    return isPalindrome(s, start + 1, end - 1);
}

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    if (isPalindrome(s, 0, s.length() - 1)){
        cout << "It is a palindrome!" << endl;
    }
    else{
        cout << "Not a palindrome." << endl;
    }
    return 0;
}
