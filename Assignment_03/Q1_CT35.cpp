/*
Assignment #3
Question 1:
Write a recursive function to compute the factorial of a non-negative integer n.
*/

#include <iostream>
using namespace std;

/*
   Name: Syed Wahaaj Ali
   Roll No: CT-24035
   Section A - CSIT
*/

int factorial(int n) {
    if (n == 0 || n == 1)
        return 1; // Base case
    return n * factorial(n - 1);
}

int main() {
    int n;
    cout << "Enter a non-negative integer: ";
    cin >> n;
    cout << "Factorial of " << n << " is " << factorial(n) << endl;
    return 0;
}
