#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int n) {
    int l = 0, r = 0;
    int ans = 0, temp = 0;

    while (r < n) {
        if (arr[r] == 0) { 
            temp++; 
        } else { 
            ans = max(ans, temp); 
            temp = 0; // Reset the temp counter
        }
        r++; // Always move r forward
    }
    ans = max(ans, temp); // Handle case where array ends with zeroes
    cout << ans << endl;
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
