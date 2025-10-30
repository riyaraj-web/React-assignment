// // C++ program for implementation of Heap Sort using vector
// Complexity Analysis of Heap Sort
// Time Complexity: O(n log n)
// Auxiliary Space: O(log n), due to the recursive call stack. However, auxiliary space can be O(1) for iterative implementation.

#include <bits/stdc++.h>
using namespace std;

// To heapify a subtree rooted with node i
// which is an index in arr[].
void heapify(vector<int>& arr, int n, int i){
    int largest = i;
    int l = 2 * i + 1;

    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr){
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
  
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
