#include<bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

void solve(vector<int> &a, int n) {
    vector <int> b (n,0);
    int sum = n+1;

    for(int i = 0; i<n; i++) {
        b[i] = sum - a[i];   
    }

    for(int i = 0; i<n; i++) {
        cout << b[i] << " ";
    }cout << endl;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector <int> a(n);
        for(int i = 0; i<n; i++) {
            cin >> a[i];
        }
        solve(a,n);

    }
    return 0;
}