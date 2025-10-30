#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int key) {
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == key)
        return mid;
    else if (arr[mid] < key)
        return binarySearch(arr, mid + 1, high, key);
    else
        return binarySearch(arr, low, mid - 1, key);
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 7;

    int result = binarySearch(arr, 0, n - 1, key);
    if (result != -1)
        cout << "Element found at index " << result;
    else
        cout << "Element not found";
}
