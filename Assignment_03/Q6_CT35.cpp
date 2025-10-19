/*
Assignment #3
Question 6:
Write a program to solve the Towers of Hanoi puzzle recursively. The function should take the
number of disks and the source, destination, and auxiliary pegs as arguments, and print the steps
to move the disks.
*/

#include <iostream>
using namespace std;

/*
   Name: Syed Wahaaj Ali
   Roll No: CT-24035
   Section A - CSIT
*/

void towersOfHanoi(int n, char source, char destination, char auxiliary) {
	if (n == 1) {
		cout << "Move disk " << n << " from " << source << " to " << destination << endl;
		return;
	}
	towersOfHanoi(n - 1, source, auxiliary, destination);
	cout << "Move disk " << n << " from " << source << " to " << destination << endl;
	towersOfHanoi(n - 1, auxiliary, destination, source);
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;
    towersOfHanoi(n, 'A', 'C', 'B');
    return 0;
}
