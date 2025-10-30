#include <iostream>
#include <algorithm>
using namespace std;

void countingSort(int arr[], int n) {
    int max = *max_element(arr, arr + n);
    int count[max + 1] = {0};

    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    int index = 0;
    for (int i = 0; i <= max; i++)
        while (count[i]--)
            arr[index++] = i;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    countingSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
