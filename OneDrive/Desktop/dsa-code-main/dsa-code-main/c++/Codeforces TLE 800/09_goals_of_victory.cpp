#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

void solve(vector<int> &arr, int n) {
    int ans = 0;

    for(int i = 0; i<n; i++) {
        ans += arr[i];
    }

    cout<< (-1 * ans) << endl;
}


int main() {
    int t;
    cin >> t;

    while(t--) {
        int n ;
        cin >> n;

        vector<int> arr(n-1);

        for(int i = 0; i<n-1; i++) {
            cin >> arr[i];
        }

        solve(arr, n-1);
    }
    return 0;
}