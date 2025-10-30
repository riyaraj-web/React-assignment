#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr , int m) {
    reverse(arr.begin() + m + 1, arr.end());       	
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        reverseArray(arr, m);

        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}