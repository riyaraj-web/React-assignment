#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int k, int n) {

    bool f = false;
    for(int i = 0; i<n; i++) {
        if(arr[i] == k) {
            cout<<"YES"<<endl;
            f = true;
            break;
        }
    }

    if(!f) {
        cout<<"NO" <<endl;
    }

}

int main() {

    int t;
    cin >> t;

    while (t--) {
        int n , k;
        cin >> n >> k;

        vector<int> arr(n);
        for(int i = 0; i<n; i++) {
            cin >> arr[i];
        }

        solve(arr, k, n);
    }
    return 0;
}