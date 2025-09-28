/* 
Assignment 01

Question 2:
Create a function that takes a list of integers and returns True if the list contains duplicate
elements, otherwise return False.

*/

#include <iostream>
using namespace std;

/*
   Name: Syed Wahaaj Ali
   Roll No: CT-24035
   Section A - CSIT
*/

bool hasDuplicate(int arr[], int n) {
    // check each element against every other element
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                return true; // duplicate found
            }
        }
    }
    return false; // no duplicates
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int *arr = new int[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (hasDuplicate(arr, n)){
        cout << "Duplicates exist" << endl;
    } else {
        cout << "No duplicates" << endl;
    }
    delete[] arr;
    return 0;
}
