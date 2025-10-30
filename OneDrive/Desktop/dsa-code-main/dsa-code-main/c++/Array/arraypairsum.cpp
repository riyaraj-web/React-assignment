#include <iostream>
using namespace std;

void findPairsBruteForce(int arr[], int n, int target) {
    cout << "Pairs with sum " << target << " are:\n";
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                cout << "(" << arr[i] << ", " << arr[j] << ")\n";
            }
        }
    }
}

int main() {
    int arr[] = {1, 5, 7, -1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 6;

    findPairsBruteForce(arr, n, target);
    return 0;
}
