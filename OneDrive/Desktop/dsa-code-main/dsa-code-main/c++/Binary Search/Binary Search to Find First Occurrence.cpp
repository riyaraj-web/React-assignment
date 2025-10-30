#include <iostream>
using namespace std;

int firstOccurrence(int arr[], int n, int key) {
    int low = 0, high = n - 1, result = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            result = mid;     // record index
            high = mid - 1;   // look for earlier occurrence
        }
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return result;
}

int main() {
    int arr[] = {1, 2, 4, 4, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 4;

    int result = firstOccurrence(arr, n, key);
    if (result != -1)
        cout << "First occurrence of " << key << " is at index " << result;
    else
        cout << "Element not found";
}
