/*
Assignment #2
Question 7:
Given an array of integers representing the heights of a histogram's bars, where each bar has a width of 1, find the area of the largest rectangle in the histogram.
Use a stack-based approach to solve this in O(n) time.
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
   Name: Syed Wahaaj Ali
   Roll No: CT-24035
   Section A - CSIT
*/

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack<int> st;
    vector<int> left(n), right(n);

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }

        if (st.empty()) {
            right[i] = n;
        } else {
            right[i] = st.top();
        }

        st.push(i);
    }

    while (!st.empty()) {
        st.pop();
    }

    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }

        if (st.empty()) {
            left[i] = -1;
        } else {
            left[i] = st.top();
        }

        st.push(i);
    }

    int largestArea = 0;
    for (int i = 0; i < n; i++) {
        int width = right[i] - left[i] - 1;
        int currentArea = heights[i] * width;
        largestArea = max(largestArea, currentArea);
    }

    return largestArea;
}

int main() {
    int n;
    cout << "Enter number of bars: ";
    cin >> n;

    if (n <= 0) {
        cout << "\nInvalid number of bars (must be positive)." << endl;
        return 0;
    }

    vector<int> heights(n);
    cout << "Enter the heights of bars: ";
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    int result = largestRectangleArea(heights);
    cout << "\nLargest Rectangle Area = " << result << "\n";

    return 0;
}
