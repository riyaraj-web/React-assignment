#include <iostream>
#include <string>
#include <vector>
// #include <bits/stdc++.h>
#include <algorithm>
using namespace std;

void solve(vector<int> &arr, int n) {

    vector<int> ans;
    ans.push_back(arr[0]);

    for(int i = 1; i<n; i++) {
        if(arr[i] >= arr[i-1]) {
            ans.push_back(arr[i]);
        }
        else {
            ans.push_back(arr[i]);
            ans.push_back(arr[i]);
        }
    }

    cout << ans.size() <<endl;
    for(auto x : ans) {
        cout << x << " ";
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

        solve (arr, n);
    }
    return 0;
}