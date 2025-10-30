#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

void solve(vector<int> &arr, int n) {
    int odds = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 1) {
            odds++;
        }
    }

    if (odds % 2 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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