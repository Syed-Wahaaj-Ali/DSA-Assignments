/*
Assignment #2
Question 10:
Given an array and a window size k, find the maximum element in each sliding window of size k.
Use a deque (double-ended queue) to solve this problem efficiently in O(n) time.
*/

#include <iostream>
#include <deque>
#include <vector>
using namespace std;

/*
   Name: Syed Wahaaj Ali
   Roll No: CT-24035
   Section A - CSIT
*/

void printMaxInWindow(const vector<int>& arr, int k) {
    if (arr.empty() || k <= 0) {
        cout << "Invalid input.\n";
        return;
    }

    deque<int> dq;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        while (!dq.empty() && arr[dq.back()] <= arr[i])
            dq.pop_back();

        dq.push_back(i);

        if (i >= k - 1)
            cout << arr[dq.front()] << " ";
    }

    cout << endl;
}

int main() {
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid size.\n";
        return 0;
    }

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter window size (k): ";
    cin >> k;

    cout << "\nMaximum elements in each sliding window: ";
    printMaxInWindow(arr, k);

    return 0;
}
