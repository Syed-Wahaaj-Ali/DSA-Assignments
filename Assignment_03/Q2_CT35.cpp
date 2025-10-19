/*
Assignment #3
Question 2:
Create a recursive function that takes a positive integer and returns the sum of its digits. For
example, sum_digits(123) should return 6.
*/

#include <iostream>
using namespace std;

/*
   Name: Syed Wahaaj Ali
   Roll No: CT-24035
   Section A - CSIT
*/

int sumOfDigits(int n) {
    if (n == 0)
        return 0;
    return (n % 10) + sumOfDigits(n / 10);
}

int main() {
    int num;
    cout << "Enter a positive integer: ";
    cin >> num;
    cout << "Sum of digits = " << sumOfDigits(num) << endl;
    return 0;
}
