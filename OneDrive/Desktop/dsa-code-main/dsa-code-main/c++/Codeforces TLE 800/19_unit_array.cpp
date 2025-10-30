#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int n) {
    int f1 = 0;
    int f2 = 0;

    int ans = 0;

    for(auto a: arr) {
        if(a == 1) {
            f2++;
        }
        else {
            f1++;
        }
    }

    if(f1 <= f2) {
        if(f1%2 == 1) {
            cout << 1 << endl;
        }
        else {
            cout << 0 << endl;
        }
    }
    else {
        int ops = f1 - n/2;
        if((n/2) % 2 == 1) {
            ops++;
        }
        cout << ops << endl;
    }
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        
        vector<int> arr(n);

        for(int i = 0; i<n; i++) {
            cin >> arr[i];
        }

        solve(arr, n);
    }
    return 0;
}