#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void solve(vector<int> &arr, int n) {
    if (n == 2) {
        cout << "Yes" << endl;
        return;
    }

    unordered_map<int, int> mp;
    bool yes = true;

    for (int i = 0; i < n; i++) {
        mp[arr[i]]++;

        if (mp.size() > 2) {
            yes = false;
            break;
        }
    }

    if (mp.size() == 1) {
        // nothing
    } else if (mp.size() == 2) {
        int f1 = begin(mp)->second;  // freq of first element

        if (f1 != n / 2 && f1 != (n + 1) / 2) {
            yes = false;
        }
    } else {
        // nothing
    }

    if (yes)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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