#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

void solve(vector<int> &arr, int n) {
    int smallest = arr[0];
    bool f = true;

    for (int i = 1; i < n; i++) {
        if (smallest > arr[i]) {
            cout << "NO" << endl;
            f = false;
            break;
        }
    }
    if (f) {
        cout << "YES" << endl;
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