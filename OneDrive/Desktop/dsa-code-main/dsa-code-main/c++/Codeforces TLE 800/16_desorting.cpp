#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int n) {
    if (!is_sorted(arr.begin(), arr.end())) {
        cout << 0 << endl;
    } else {
        int diff = INT32_MAX;

        for(int i = 1 ;i<n; i++) {
            diff = min(diff , arr[i] - arr[i-1]);
        }

        int ops = diff/2 + 1;
        cout << ops << endl;
        
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        solve(arr, n);
    }
    return 0;
}