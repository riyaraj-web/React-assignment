/*
    Problem: Bubble Sort
    Language: C++
    Author: <your-name>
    Date: <today’s-date>
    Description:
        Implement Bubble Sort to sort an array in ascending order.

    Example:
        Input: [5, 1, 4, 2, 8]
        Output: [1, 2, 4, 5, 8]

    Time Complexity: O(n^2)
    Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // optimization: stop if no swaps
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    bubbleSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    return 0;
}
