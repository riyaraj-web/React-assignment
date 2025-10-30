/*
    Problem: Shell Sort
    Language: C++
    Author: alisha1510
    Date: 20 October 2025
    Description:
        Implement Shell Sort.

    Example:
        Enter number of elements: 6
        Enter 6 elements: 45 12 78 23 56 10
        Sorted array: 10 12 23 45 56 78

    Time Complexity: O(n log n)
    Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    shellSort(arr, n);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}
