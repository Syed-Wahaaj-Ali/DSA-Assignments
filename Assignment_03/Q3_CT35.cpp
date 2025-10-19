/*
Assignment #3
Question 3:
Write a recursive function to find the nth number in the Fibonacci sequence. The sequence starts
with 0, 1 and each subsequent number is the sum of the previous two.
*/

#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1; 
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Fibonacci number at position " << n << " = " << fibonacci(n) << endl;
    return 0;
}
