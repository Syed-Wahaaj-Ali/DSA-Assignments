/* 
Assignment 01

Question 1:
Given an array of integers and a target sum, find two numbers in the array that add up to
the target sum. Return their indices. You can assume there will be exactly one solution

*/

#include <iostream>
using namespace std;

/*
   Name: Syed Wahaaj Ali
   Roll No: CT-24035
   Section A - CSIT
*/

// function to find two numbers that add to target
// we will return their indices
void findTwoSum(int arr[], int n, int target) {
	// using two loops to check every pair
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			// check if these two numbers add to target
			if (arr[i] + arr[j] == target) {
				cout << "Indices: " << i << " and " << j << endl;
				cout << "Numbers: " << arr[i] << " and " << arr[j] << endl;
				return; // stop after finding one pair
			}
		}
	}
	// if no pair found
	cout << "No pair found" << endl;
}

int main() {
	int n;
	cout << "Enter size of array: ";
	cin >> n;

	// create dynamic array of size n
	int* arr = new int[n];

	cout << "Enter array elements: ";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int target;
	cout << "Enter target sum: ";
	cin >> target;

	findTwoSum(arr, n, target);

	// free memory
	delete[] arr;
	return 0;
}
